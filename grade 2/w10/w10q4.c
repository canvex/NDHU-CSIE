#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char a[87][87], b[87][87];
    memset(a, 0, sizeof(a));
    int line = 0;
    while (scanf("%s", a[line]) != EOF)
        line++;
    memcpy(b, a, sizeof(a));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < line; j++) {
            for (int k = 0; k < strlen(a[0]); k++) {
                if (a[j][k] == '1') {
                    int count = 0;
                    if (a[j - 1][k - 1] == '1')  // 左上
                        count++;
                    if (a[j][k - 1] == '1')  // 上
                        count++;
                    if (a[j + 1][k - 1] == '1')  // 右上
                        count++;
                    if (a[j - 1][k] == '1')  // 左
                        count++;
                    if (a[j + 1][k] == '1')  // 右
                        count++;
                    if (a[j - 1][k + 1] == '1')  // 左下
                        count++;
                    if (a[j][k + 1] == '1')  // 下
                        count++;
                    if (a[j + 1][k + 1] == '1')  // 右下
                        count++;
                    if (count < 2)
                        b[j][k] = '0';
                    else if (count >= 4)
                        b[j][k] = '0';
                } else if (a[j][k] == '0') {
                    int count = 0;
                    if (a[j - 1][k - 1] == '1')  // 左上
                        count++;
                    if (a[j][k - 1] == '1')  // 上
                        count++;
                    if (a[j + 1][k - 1] == '1')  // 右上
                        count++;
                    if (a[j - 1][k] == '1')  // 左
                        count++;
                    if (a[j + 1][k] == '1')  // 右
                        count++;
                    if (a[j - 1][k + 1] == '1')  // 左下
                        count++;
                    if (a[j][k + 1] == '1')  // 下
                        count++;
                    if (a[j + 1][k + 1] == '1')  // 右下
                        count++;
                    if (count == 3)
                        b[j][k] = '1';
                }
            }
        }
        memcpy(a, b, sizeof(b));
    }
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < strlen(a[0]); j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}