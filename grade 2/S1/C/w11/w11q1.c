/*******************************************
function name: replace
description: When mode is 1, replace the first target finded in source with the
replacement. When mode is 2, replace left-most target by replacement until there
are no targets in the source. return value: Return the result after replace.
*******************************************/
#include <stdio.h>
#include <string.h>

char* replace(char* source, char* target, char* replacement, int mode) {
    int len = strlen(source);
    int tlen = strlen(target);
    int rlen = strlen(replacement);

    if (mode == 1) {
        char* found = strstr(source, target);
        if (found != NULL) {
            memmove(found + rlen, found + tlen, strlen(found + tlen) + 1);
            memcpy(found, replacement, rlen);
        }
    } else if (mode == 2) {
        int replaced = 0;
        char* found = strstr(source, target);
        while (found != NULL) {
            memmove(found + rlen, found + tlen,
                    strlen(found + tlen) + 1);  // 先找位置
            memcpy(found, replacement, rlen);  // 蓋過位置 (不是找值蓋過去)
            replaced = 1;
            found = strstr(found + rlen, target);  // 調整起始位置
        }
        if (replaced) {
            // 如果有進行替換，則遞迴呼叫 replace 函數繼續檢查
            replace(source, target, replacement, mode);
        }
    }
    return source;
}

int main() {
    char s[] = "as;idufnfkasdffca";
    char t[] = "fc";
    char r[] = "c";
    char* result;
    result = replace(s, t, r, 2);
    printf("%s", result);

    return 0;
}