#include <stdio.h>
#include <string.h>

void generateLookAndSay(char* current, int n);

int main() {
    int N;

    // 輸入N的值
    scanf("%d", &N);

    // 開始生成Look-and-Say序列
    char current[100] = "1";  // 初始序列為"1"
    generateLookAndSay(current, N);

    return 0;
}

void generateLookAndSay(char* current, int n) {
    if (n <= 0) {
        return;
    }

    printf("%s\n", current);  // 輸出當前序列

    // 下一項的生成
    char next[2 * strlen(current) + 1];  // 确保足夠的空间
    next[0] = '\0';                      // 初始化next序列
    int count = 1;
    char digit = current[0];

    for (int i = 1; current[i] != '\0'; ++i) {
        if (current[i] == digit) {
            count++;
        } else {
            // 將count和digit轉換為字符，並追加到next序列中
            sprintf(next + strlen(next), "%d%c", count, digit);

            // 更新digit和count
            digit = current[i];
            count = 1;
        }
    }

    // 將最後一個數字追加到next序列中
    sprintf(next + strlen(next), "%d%c", count, digit);

    // 遞迴生成下一項
    generateLookAndSay(next, n - 1);
}