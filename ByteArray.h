/*
 * ByteArray.h
 *
 *  Created on: Jul 23, 2018
 *      Author: hyhlik
 */

#ifndef BYTEARRAY_H_
#define BYTEARRAY_H_

#include <stdbool.h>


/////////////////////////////////////////////////
/* @brief used in arrayCpy() function
 */
enum {
  BIG, LITTLE
} endian;


void pHex(uint8_t* str, int len);
void pHex_nl(uint8_t* str, int len);
void pHex_tit(char* title, uint8_t* data, int data_len);

void pAscii(uint8_t* str, int len);
void pAscii_nl(uint8_t* str, int len);
void pAscii_tit(char* title, uint8_t* data, int data_len);


void arrayCpy(uint8_t* target, uint8_t* array, int start, int stop, int endn);

int convert_ASCIIbyteHexString_to_byteArray(uint8_t* out, char* in);

bool arraysEqual(uint8_t* array1, uint8_t* array2, int length);
bool arraysEqualL(uint8_t* array1, uint8_t* array2, int len);
bool arrayIsZeros(uint8_t* array, int len);

uint8_t getXor(uint8_t* array, uint8_t len);





#endif /* BYTEARRAY_H_ */
