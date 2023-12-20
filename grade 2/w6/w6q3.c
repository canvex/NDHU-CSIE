#include <ctype.h>
#include <stdio.h>

int main() {
    char sentence[1000];
    int capitalize = 1;  // 初始設置為 1，表示下一個字符應該大寫

    while (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        for (int i = 0; sentence[i] != '\0'; i++) {
            if (capitalize && isalpha(sentence[i])) {
                sentence[i] = toupper(sentence[i]);
                capitalize =
                    0;  // 將 capitalize 設置為 0，表示下一個字符不應該大寫
            } else if (sentence[i] == '.' || sentence[i] == '!' ||
                       sentence[i] == '?') {
                capitalize = 1;  // 如果遇到句號、驚嘆號或問號，將 capitalize
                // 設置為 1，表示下一個字符應該大寫
            } else if (sentence[i] == '%')  // 遇到%後要小寫
            {
                capitalize = 0;
            }
        }
        printf("%s", sentence);
    }

    return 0;
}
