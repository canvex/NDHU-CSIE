#include <stdio.h>
#include <stdlib.h>

// c,d return 1 表示c放d後面   c d
// c,d return -1 表示c放d前面  c d

int m;  // 用於存儲除數

// 比較函數，用於 qsort
int comp(const void* a, const void* b) {
    int c = *(int*)a;  // 將指針轉換為整數
    int d = *(int*)b;

    // 第一步，根據除 m 的餘數進行比較(小->大)
    if (c % m > d % m)
        return 1;
    if (c % m < d % m)
        return -1;
    if (c % m == d % m)  // 如果餘數相同
    {
        // 第二步，奇數排前面，偶數排後面
        if (abs(c % 2) > abs(d % 2))
            return -1;  // 比較絕對值為奇數的大小
        if (abs(c % 2) < abs(d % 2))
            return 1;

        // 第三步，如果兩者都是奇數(大->小)
        if (abs(c % 2) == 1 && abs(c % 2) == 1)  //
        {
            if (c > d)
                return -1;  // 比較整數大小
            if (c < d)
                return 1;
        }
        // 第四步，如果兩者都是偶數(小->大)
        if (c % 2 == 0 && d % 2 == 0)  //
        {
            if (c > d)
                return 1;  // 比較整數大小
            if (c < d)
                return -1;
        }
    }
}

// 主函數
int main() {
    int n;
    while (scanf("%d %d", &n, &m))  // 循環讀取 n 和 m
    {
        printf("%d %d\n", n, m);  // 輸出 n 和 m
        if (n == 0 && m == 0)
            return 0;  // 如果 n 和 m 都為 0，則結束程序
        int arr[n];    // 創建一個大小為 n 的整數陣列
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);          // 逐個讀取陣列元素
        qsort(arr, n, sizeof(int), comp);  // 使用 qsort 對陣列進行排序
        for (int i = 0; i < n; i++)
            printf("%d\n", arr[i]);  // 輸出排序後的陣列元素
    }
}
