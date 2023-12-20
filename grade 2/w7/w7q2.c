#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25

int record[MAX] = {-1};
int pos[MAX][MAX];

// 將方塊放回原處
void move_back(int src, int pos_src) {
    int i, j, k;
    // 找到方塊 src 在 pos_src 中的位置
    for (i = 0; i < MAX; i++) {
        if (pos[pos_src][i] == src)
            break;
    }
    // 將方塊 src 之上的方塊移到 src 的位置
    for (j = i + 1; j < MAX; j++) {
        if (pos[pos_src][j] == -1)  // 上面沒東西
            break;
        // 在 pos_src 中找到一個空位置，移動方塊
        for (
            k = 0; k < MAX;
            k++) {  // 找空格，如果有東西則往上放一格(比如7要放回去:pos[7][0]有東西->放在pos[7][1])
            if (pos[pos[pos_src][j]][k] == -1) {  // 檢查放回去的值那格是空的
                pos[pos[pos_src][j]][k] = pos[pos_src][j];  // 將東西放回去位置
                record[pos[pos_src][j]] = pos[pos_src][j];  // 更新回原本位置
                break;
            }
        }
        // 將原位置設為空
        pos[pos[pos_src][j]][0] =
            pos[pos_src][j];   // 改為將方塊放回原處的最底部
        pos[pos_src][j] = -1;  // 清空src之上的方塊
    }
}

// 移動方塊
void move(int src, int pos_des) {
    int i, j, k;
    int pos_src = record[src];
    // 找到方塊 src 在 pos_src 中的位置
    for (i = 0; i < MAX; i++) {
        if (pos[pos_src][i] == src)
            break;
    }
    // 將方塊 src 以及之上的方塊移動到目標位置 pos_des

    for (j = i; j < MAX; j++) {
        if (pos[pos_src][j] == -1)
            break;
        // 在 pos_des 中找到一個空位置，移動方塊

        for (k = 0; k < MAX; k++) {
            if (pos[pos_des][k] == -1) {
                pos[pos_des][k] = pos[pos_src][j];
                record[pos[pos_des][k]] = pos_des;
                break;
            }
        }
        // 將原位置設為空
        pos[pos_src][j] = -1;  // 清空src之上的方塊
    }
}
// 將方塊 a 移動到方塊 b 之上，同時將相應的方塊歸位
void move_onto(int a, int b) {
    int pos_a = record[a];
    int pos_b = record[b];
    // 將 a 之上的方塊歸位
    move_back(a, pos_a);
    // 將 b 之上的方塊歸位
    move_back(b, pos_b);
    // 將 a 移動到 b 之上
    move(a, pos_b);
}

void move_over(int a, int b) {
    int pos_a = record[a];
    int pos_b = record[b];
    move_back(a, pos_a);
    move(a, pos_b);
}
void pile_onto(int a, int b) {
    int pos_a = record[a];
    int pos_b = record[b];
    move_back(b, pos_b);
    move(a, pos_b);
}
void pile_over(int a, int b) {
    int pos_a = record[a];
    int pos_b = record[b];
    move(a, pos_b);
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    // 初始化位置陣列
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            pos[i][j] = -1;
    // 初始化方塊位置
    for (int i = 0; i < n; i++)
        record[i] = i;
    // 將方塊放置在初始位置
    for (int i = 0; i < n; i++)
        pos[i][0] = i;

    char instruction[MAX];
    char movement[MAX];
    char position[MAX];

    gets(instruction);  // 去除 "\n"
                        // 獲取指令
    while ((gets(instruction))) {
        if (strcmp(instruction, "quit") == 0)
            break;
        sscanf(instruction, "%s %d %s %d", movement, &a, position, &b);
        if (a == b || record[a] == record[b])
            continue;
        if (strcmp(movement, "move") == 0 && strcmp(position, "onto") == 0)
            move_onto(a, b);
        else if (strcmp(movement, "move") == 0 && strcmp(position, "over") == 0)
            move_over(a, b);
        else if (strcmp(movement, "pile") == 0 && strcmp(position, "onto") == 0)
            pile_onto(a, b);
        else if (strcmp(movement, "pile") == 0 && strcmp(position, "over") == 0)
            pile_over(a, b);
        else
            return 1;
    }
    // 輸出每個位置上的方塊序列
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < MAX; j++) {
            if (pos[i][j] == -1) {
                printf("\n");
                break;
            }
            printf(" ");
            printf("%d", pos[i][j]);
        }
    }
    return 0;
    // https://github.com/evshary/UVA/blob/master/101%20-%20The%20Blocks%20Problem.c
}