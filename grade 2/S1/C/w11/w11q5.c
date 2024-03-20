/*************************************************************
function name: convertToDifferentBase
description: Convert a decimal number @dec to the number with different @base
and store the result as a string in result return vaule: Result after convert.
notice: The letter you see in the number should be upper case.
*************************************************************/

#include <stdio.h>
int i = 0, j = 0;
char ans[100];
char* convertToDifferentBase(int dec, int base, char* result) {
    int remainder = 0;

    if (dec != 0) {
        remainder = dec % base;
        dec /= base;
        // 轉換餘數為十六進制字元
        if (remainder < 10) {
            result[i] = remainder + '0';
        } else {
            result[i] = remainder - 10 + 'A';
        }
        i++;
        convertToDifferentBase(dec, base, result);
    }
    result[i] = '\0';
    // 確保在遞迴的最後返回結果指標
    for (i = i - 1; i >= 0; i--) {
        ans[j] = result[i];
        j++;
    }
    ans[j] = '\0';
    return ans;
}

// int main() {
//     char result[100];
//     printf("ans: %s", convertToDifferentBase(42341, 8, result));
//     return 0;
// }
