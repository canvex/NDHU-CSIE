// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>

// char s[1000];

// void init() {
//     fgets(s, 1000, stdin);
// }

int main() {
    init();
    char* str = s;
    int sum = 0;

    // 遍歷字串中的每個字符
    for (int i = 0; i < strlen(str); i++) {
        // 如果當前字符是數字
        if (isdigit(str[i])) {
            // 將連續的數字擷取並轉換為整數
            int num = 0;
            while (isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            // 將取得的數字加到總和中
            sum += num;
        }
    }

    printf("%d", sum);
    return 0;
}
