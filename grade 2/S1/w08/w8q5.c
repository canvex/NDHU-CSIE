#include <stdio.h>
#include <string.h>

// 函數用於檢查贏家
char* checkWinner(char board[19][20]) {
    // 檢查水平方向
    for (int i = 0; i < 19; i++) {
        if (strstr(board[i], "OOOOO") != NULL) {
            return "White";
        } else if (strstr(board[i], "XXXXX") != NULL) {
            return "Black";
        }  // strstr 用於在一個字串中尋找另一個字串的第一次出現位置
    }

    // 檢查垂直方向
    for (int j = 0; j < 19; j++) {
        char column[20];
        for (int i = 0; i < 19; i++) {
            column[i] = board[i][j];
        }
        column[19] = '\0';
        if (strstr(column, "OOOOO") != NULL) {
            return "White";
        } else if (strstr(column, "XXXXX") != NULL) {
            return "Black";
        }
    }

    // 檢查斜線方向（左上到右下）
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            char diagonal[6];
            for (int k = 0; k < 5; k++) {
                diagonal[k] = board[i + k][j + k];
            }
            diagonal[5] = '\0';
            if (strcmp(diagonal, "OOOOO") == 0) {
                return "White";
            } else if (strcmp(diagonal, "XXXXX") == 0) {
                return "Black";
            }
        }
    }

    // 檢查斜線方向（右上到左下）
    for (int i = 0; i < 15; i++) {
        for (int j = 4; j < 19; j++) {
            char diagonal[6];
            for (int k = 0; k < 5; k++) {
                diagonal[k] = board[i + k][j - k];
            }
            diagonal[5] = '\0';
            if (strcmp(diagonal, "OOOOO") == 0) {
                return "White";
            } else if (strcmp(diagonal, "XXXXX") == 0) {
                return "Black";
            }
        }
    }

    return "No winner";
}

int main() {
    char board[19][20];

    // 讀取輸入
    for (int i = 0; i < 19; i++) {
        scanf("%s", board[i]);
    }

    // 判斷贏家並輸出結果
    char* result = checkWinner(board);
    printf("%s\n", result);

    return 0;
}
