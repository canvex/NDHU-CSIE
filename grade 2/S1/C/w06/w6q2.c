#include <stdio.h>

int main() {
    int n, i;
    int ans[32];
    scanf("%d", &n);
    while (n != 0) {
        ans[i] = n % 2;  // 餘數放入陣列
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {  // 反轉輸出
        printf("%d", ans[j]);
    }
    return 0;
}
