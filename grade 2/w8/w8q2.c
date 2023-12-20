#include <stdio.h>

// 定義迷宮大小的最大值
#define MAX_SIZE 100

// 函式宣告
int isPathExist(int maze[MAX_SIZE][MAX_SIZE], int n, int row, int col);

int main() {
    int n;
    scanf("%d", &n);

    // 宣告迷宮陣列
    int maze[MAX_SIZE][MAX_SIZE];

    // 讀入迷宮資訊
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    // 呼叫函式判斷迷宮是否有路徑
    if (isPathExist(maze, n, 0, 0)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// 判斷迷宮是否有路徑的函式
int isPathExist(int maze[MAX_SIZE][MAX_SIZE], int n, int row, int col) {
    // 超出迷宮範圍或遇到障礙物，返回false
    if (row < 0 || row >= n || col < 0 || col >= n || maze[row][col] == 1) {
        return 0;
    }

    // 已經到達迷宮出口，返回true
    if (row == n - 1 && col == n - 1) {
        return 1;
    }

    // 標記目前位置為已訪問
    maze[row][col] = 1;

    // 向上、下、左、右四個方向遞迴尋找路徑
    if (isPathExist(maze, n, row - 1, col) ||  // 向上
        isPathExist(maze, n, row + 1, col) ||  // 向下
        isPathExist(maze, n, row, col - 1) ||  // 向左
        isPathExist(maze, n, row, col + 1)) {  // 向右
        return 1;
    }

    return 0;
}
