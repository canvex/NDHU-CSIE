#include <stdio.h>

// 定義一個交換兩數的函式
void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// 全域變數，分別表示總人數、每次跳過的人數、臨時變數、存放每個人的陣列
int n, k, t, m;
int v[100];

// 函式用來模擬每次刪除的動作
int ask(int a, int b, int c) {  // a=當前位置，b=每次跳過幾個人，c=總人數
    while (b != 0) {
        a = (a + 1) % c;  // 向後枚舉位置
        if (v[a] != -1)
            --b;  // 如果有人就跳過
    }
    return a;
}

// 主程式
int main() {
    while (scanf("%d %d", &n, &k) == 2) {
        if (n == 0 && k == 0)  // n=7 k=3
            break;
        for (int i = 0; i <= n; ++i)
            v[i] = i;     // 初始化陣列，每個人的位置
        m = (k - 1) % n;  // 計算第一次刪除的位置
        for (int i = 1; i < n; ++i) {
            v[m] = -1;               // 刪除這個人
            int kkk = ask(m, k, n);  // 找到從這個點開始數的第k個人，3
            swap(&v[kkk], &v[m]);  // 讓他站在出圈人的位置上
            m = ask(m, k, n);      // 再次開始數後來的人
        }
        printf("%d\n", (n - v[m]) % n + 1);  // 印出最後留下的人的編號
    }
    return 0;
}
