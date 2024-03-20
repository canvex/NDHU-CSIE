#include <stdbool.h>
#include <stdio.h>

int main() {
    // 宣告變數
    int l, h, r, high = 0, high_r = 0;
    int p[10001] = {0};

    // 讀取矩形資訊，更新 p 陣列
    while (scanf("%d%d%d", &l, &h, &r) != EOF) {
        for (int i = l; i < r; i++) {
            // 更新位置 i 的高度為 h
            if (h > p[i])
                p[i] = h;

            // 更新 high_r，以追蹤最大的 r
            if (r > high_r)
                high_r = r;
        }
    }

    // 控制輸出格式的布林變數
    bool space = true;

    // 遍歷 p 陣列，輸出描述矩形的序列
    for (int i = 0; i <= high_r; i++) {
        // 判斷高度非零的位置
        if (space && p[i] != 0) {
            // 輸出位置 i，表示矩形的起始位置
            printf("%d", i);
            space = false;  // 下一個高度非零的位置不再是起始位置
            continue;
        }

        // 判斷高度變化的位置
        if (!space && p[i - 1] != p[i]) {
            // 輸出位置 i-1 的高度以及位置 i，表示矩形的高度發生變化
            printf(" %d %d", p[i - 1], i);
        }
    }

    // 輸出 0，表示矩形序列的結束
    printf(" %d\n", 0);

    return 0;
}
