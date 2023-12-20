#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    char* roman[13] = {"I",  "IV", "V",  "IX", "X",  "XL", "L",
                       "XC", "C",  "CD", "D",  "CM", "M"};
    int num[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    for (int i = 12; i >= 0; i--) {
        if (n >= num[i]) {
            printf("%s", roman[i]);
            n = n - num[i];
            if (n >= num[i])
                i++;
            // printf("%d\n",n);
        }
    }

    return 0;
}