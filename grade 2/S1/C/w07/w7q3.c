#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 比較函數用於排序
int compare(const void* a, const void* b) {
    // 先比較 x 軸，如果相同再比較 y 軸
    if (((int*)a)[0] == ((int*)b)[0]) {
        return ((int*)a)[1] - ((int*)b)[1];
    }
    return ((int*)a)[0] - ((int*)b)[0];
}

// 計算兩點之間的距離
double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int C;  // 測試資料的組數
    scanf("%d", &C);

    while (C--) {
        int N;  // 點的數量
        scanf("%d", &N);

        int points[N][2];  // 儲存點的座標
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &points[i][0], &points[i][1]);
        }

        // 對點的陣列按照 x 軸和 y 軸進行排序
        qsort(points, N, sizeof(points[0]), compare);
        // 印出x-y軸
        // printf("Sorted Coordinates (x-y):\n");
        // for (int i = 0; i < N; i++) {
        //     printf("%d %d\n", points[i][0], points[i][1]);
        // }
        // printf("%d %d", points[N - 1][0], points[N - 1][1]);
        double totalLength = 0.0;
        int maxHeight = 0;

        // 計算高的山峰被照到的距離，並加總起來
        for (int i = N - 1; i >= 0; i--) {
            if (points[i][1] > maxHeight) {
                // 高的山峰被照到
                // printf("now coord is: %d %d", points[i][0], points[i][1]);
                totalLength += distance(points[i][0], points[i][1],
                                        points[i + 1][0], points[i + 1][1]) *
                               (points[i][1] - maxHeight) /
                               (points[i][1] - points[i + 1][1]);

                //  printf(" now length is %f: \n",
                //        distance(points[i][0], points[i][1], points[i + 1][0],
                //                 maxHeight) *
                //            (points[i][1] - maxHeight) /
                //            (points[i][1] - points[i + 1][1]));
                // 更新最高的山峰高度
                maxHeight = fmax(maxHeight, points[i][1]);
            }
        }

        // 最後一個點的高度
        // maxHeight = fmax(maxHeight, points[N - 1][1]);

        printf("%.2f\n", totalLength);
    }

    return 0;
}
