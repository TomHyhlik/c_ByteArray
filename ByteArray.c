#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ByteArray.h"


////////////////////////////////////////////////////
/* prints array hex numbers without \n at the end */
void pHex(uint8_t* str, int len)
{
	if(str == NULL){
		printf("Empty array to print\n");
		return;
	}
    for (int i = 0; i < len; ++i)
        printf("%.2X", str[i]);
}
////////////////////////////////////////////////////
/* prints array hex numbers with \n at the end */
void pHex_nl(uint8_t* str, int len)
{
	pHex(str, len);
    printf("\n");
}
////////////////////////////////////////////////////
void pHex_tit(char* title, uint8_t* data, int data_len)
{
	printf("%s\"", title);
	pHex(data, data_len);
	printf("\"\r\n");
}
////////////////////////////////////////////////////
void pAscii(uint8_t* str, int len)
{
	if(str == NULL){
		printf("Empty array\n");
		return;
	}
	for(int i = 0; i < len; i++){
		printf("%c", str[i]);
	}
}
////////////////////////////////////////////////////
void pAscii_nl(uint8_t* str, int len)
{
	pAscii(str, len);
	printf("\n");
}
////////////////////////////////////////////////////
void pAscii_tit(char* title, uint8_t* data, int data_len)
{
	printf("%s\"", title);
	pAscii(data, data_len);
	printf("\"\n");
}

////////////////////////////////////////////////////
/*  @brief coppy part of array to the target location
 *  @param array: da array
 *  @param target: the target memory location
 *  @param start: the starting position of array
 * @param stop: the stop position of array
 * @param endian: oprions: BIG and LITTLE
 */
void arrayCpy(uint8_t* target, uint8_t* array, int start, int stop, int endian)
{
  int i;
  switch(endian)
  {
  case LITTLE:
    for(i = 0 ; start < stop+1 ; i++, start++)
      target[i] = array[start];
  break;
  case BIG:
    for(i = 0 ; start < stop+1 ; i++, stop--)
      target[i] = array[stop];
  break;
  default:
    printf("arrayCpy: invalid input\n");
  }
}


////////////////////////////////////////////////////
/* @brief algorithm is according to the ASCII table
 * @param in points to input string
 * @param out points to output byte array, should be half size of the "in"
 * @return length of the output array, -1 if error 
 */
int convert_ASCIIbyteHexString_to_byteArray(uint8_t* out, char* in)
{
	uint8_t number;
    int in_ptr, out_ptr;
	int out_len = strlen(in)/2;

	bool isEvenChar = false;
	memset(out, 0, out_len);

	/* for each character */
	for (in_ptr = 0, out_ptr = 0; in_ptr < strlen(in); in_ptr++)
	{
		/* 1...9 */
		if(in[in_ptr] >= 48 && in[in_ptr] <= 57) {
			number = in[in_ptr] - 48;
		}
		/* A...F */
		else if (in[in_ptr] >= 65 && in[in_ptr] <= 70) {
			number = in[in_ptr] - 65 + 10;
		}
		/* a...f */
		else if (in[in_ptr] >= 97 && in[in_ptr] <= 102) {
			number = in[in_ptr] - 97 + 10;
		}
        /* skip in case of space */
        else if (in[in_ptr] == ' ') {
			continue;
        }
		else {
			printf("Invalid character: \"%d\", at possition: %d\n", in[in_ptr], in_ptr);
			return -1;
		}
		/* in case of an odd or even character */
		if (isEvenChar) {
			isEvenChar = false;
			out[out_ptr] |= number;
			out_ptr++;
		} else {
			isEvenChar = true;
			out[out_ptr] = 0;
			out[out_ptr] |= number << 4;
		}
	}
	return out_ptr;
}


////////////////////////////////////////////////////
bool arraysEqual(uint8_t* array1, uint8_t* array2, int length)
{
	for (int i = 0; i < length; i++) {
		if (array1[i] != array2[i]) {
			return false;
		}
	}

	return true;
}

///////////////////////////////////////////////////////////
uint8_t calcCRC(uint8_t* data, uint8_t data_len)
{
	uint8_t calculatedCRC = 0;

	for(int i = 0; i < data_len; i++)
		calculatedCRC ^= data[i];

	return calculatedCRC;
}

///////////////////////////////////////////////////////////
bool arrayIsZeros(uint8_t* array, int len)
{
	for(int i = 0; i < len; i++)
	{
		if(array[i] != 0)
		{
			return false;
		}
	}
	return true;
}
///////////////////////////////////////////////////////////



