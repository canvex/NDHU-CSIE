#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

int Count, white, black;
bool isb;  // 黑子
bool isw;  // 白子
char s[N + 2][N + 2];

// 深度優先搜索函數
void DFS(int x, int y) {
    // 如果超出邊界，返回
    if (x < 0 || x >= N || y < 0 || y >= N)
        return;

    // 如果當前位置為空點
    if (s[x][y] == '.') {
        s[x][y] = '*';  // 標記為已訪問
        Count++;        // 計數
    } else {
        // 如果當前位置為'O'或'X'
        if (s[x][y] == 'O')
            isw = true;  // 標記白子存在
        else if (s[x][y] == 'X')
            isb = true;  // 標記黑子存在
        return;
    }

    // 對當前位置的上下左右進行DFS
    DFS(x - 1, y);
    DFS(x + 1, y);
    DFS(x, y - 1);
    DFS(x, y + 1);
}

int main() {
    int Case;
    scanf("%d", &Case);
    gets(s[0]);  // 讀取多餘的換行符

    while (Case--) {
        white = black = 0;

        // 讀取每一行的棋盤狀態
        for (int i = 0; i < N; i++) {
            gets(s[i]);

            // 計算黑子和白子的數量
            for (int j = 0; j < N; j++)
                if (s[i][j] == 'O')
                    white++;
                else if (s[i][j] == 'X')
                    black++;
        }

        // 對每個空點進行DFS，計算領地得分
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (s[i][j] == '.') {
                    isb = isw = false;
                    Count = 0;
                    DFS(i, j);

                    // 如果同一個空點上有黑子和白子，跳過該空點
                    if (isb && isw)
                        continue;

                    // 更新黑子和白子的得分
                    if (isb)
                        black += Count;
                    else if (isw)
                        white += Count;
                }

        // 輸出結果
        printf("Black %d White %d\n", black, white);
    }

    return 0;
}
