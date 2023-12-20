#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
    int c = *(int*)a;  // 將指針轉換為整數
    int d = *(int*)b;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int a[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        qsort(a, n, sizeof(int), cmp);
        int mid1 = a[(n - 1) / 2];  // 第一個中位數
        int mid2 = a[n / 2];        // 第二個中位數
        int count = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == mid1 || a[i] == mid2)
                count++;  // 跟中位數相等的數量
        int ans =
            mid2 - mid1 +
            1;  // 計算總共有幾個可能的中位數(第一個中位數第二個中位數中間所有的值)
        printf("%d %d %d\n", mid1, count, ans);  // 輸出
    }
    return 0;
}
