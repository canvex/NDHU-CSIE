#include <stdio.h>

int main() {
    int m, n, count;
    scanf("%d%d", &n, &m);
    int arr[n][m];  // n是row，m是col

    // 輸入陣列
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // 初始化上、下、左、右四個邊界指標
    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    // 開始順時針螺旋輸出
    while (top <= bottom && left <= right) {
        // 上
        for (int i = left; i <= right; i++)
            printf("%d ", arr[top][i]);
        top++;

        // 右
        for (int i = top; i <= bottom; i++)
            printf("%d ", arr[i][right]);
        right--;

        // 下
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", arr[bottom][i]);
            bottom--;
        }

        // 左
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", arr[i][left]);
            left++;
        }
    }

    return 0;
}
