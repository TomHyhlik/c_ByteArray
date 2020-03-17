#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "../ByteArray.h"



////////////////////////////////////////////////////
int main(void)
{
    printf("AppStart......................\n");


    char  data_str[] = "53 02 07 01 04 80 49 4D 41 D4 02 F0 00 55 00 AA 00 78 30 00 00 80 0C 20 00 80 42 88 00 00 00 00 00 80 42 80 00 00 00 E0 00 FD FF 3A 00 5B 00 07 00 30 C0 B3 00 00 4F 78 00 03 00 37 00 65 00 07 00 00 4F 78 00 00 60 FE 00 1E 40 78 00 E3 4F 50 00 FA FF 32 00 1E 40 78 00 E2 4F 50 00 16 00 3A 00 1F 00 07 00 76 00 07 00 40 C0 B3 00 00 4F 78 00 03 00 37 00 80 00 07 00 00 4F 78 00 00 60 FE 00 1E 40 78 00 E4 4F 50 00 FA FF 32 00 1E 40 78 00 E5 4F 50 00 08 00 3A 00 00 40 EB 00 00 4F 78 00 76 86 A8 00 76 A6 A9 00 00 00 00 00 1E 40 78 00 00 80 FA 00 00 00 06 00 10 C0 B3 00 00 4F 78 00 76 86 A9 00 76 A6 A8 00 FF FF 37 00 00 00 FA 00 C6 26 A9 00 75 66 A8 00 00 80 FA 00 00 00 06 00 00 00 FA 00 C5 E3 A9 00 10 02 20 00 60 1E 88 00 00 00 28 00 30 1E 88 00 A0 00 20 00 20 1E 88 00 C5 E3 A8 00";



    uint8_t data[512];


    int data_size = convert_ASCIIbyteHexString_to_byteArray(data, data_str);



    pHex_nl(data, data_size);






   printf("AppEnd......................\n");
    return 0;
}