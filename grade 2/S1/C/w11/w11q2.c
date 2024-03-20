/*************************************************************
function name: convertToDifferentBase
description: Convert a decimal number @dec to the number with different @base
and store the result as a string in result return vaule: Result after convert.
notice: The letter you see in the number should be upper case.
*************************************************************/
#include <stdio.h>
int i = 0, j = 0;

char* convertToDifferentBase(int dec, int base, char* result) {
    char tmp[100];
    while (dec > 0) {
        tmp[i] = dec % base < 10 ? (dec % base + '0') : (dec % base - 10 + 'A');
        dec /= base;
        i++;
    }
    tmp[i] = '\0';
    for (i = i - 1; i >= 0; i--) {
        result[j] = tmp[i];
        j++;
    }
    result[j] = '\0';
    return result;
}

// int main() {
//     char result[100];
//     printf("%s", convertToDifferentBase(52, 16, result));
//     return 0;
// }