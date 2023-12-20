#include <stdio.h>
#include <string.h>

void longnonrepeat(char* str) {
    int n = strlen(str);  // 獲取字串的長度
    int visited[256];     // 用來存儲每個字符的索引
    memset(visited, -1,
           sizeof(visited));  // 初始化visited數組，將所有元素設置為-1
    int max_len = 0, start = 0,
        end = 0;  // 初始化最大長度、子串開始索引和結束索引
    int start_index = 0;  // 設置起始索引為0

    for (int i = 0; i < n; i++) {
        if (visited[str[i]] != -1 && start_index <= visited[str[i]]) {
            // 如果當前字符已經出現過且出現的位置在起始索引之後，更新起始索引
            start_index = visited[str[i]] + 1;
        }
        // printf("%d ", visited[str[i]]);
        if (i - start_index > max_len) {
            // 如果當前子串長度大於最大長度，更新最大長度、起始索引和結束索引
            max_len = i - start_index;
            start = start_index;  // 紀錄最後要印出最長不重複字串的開始位置
            end = i;  // 紀錄最後要印出最長不重複字串的結束位置
        }

        visited[str[i]] = i;  // 更新字符的索引位置
    }
    // printf("\n");

    // 打印最長的不重複子串
    for (int i = start; i <= end; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    int n;
    char input[1001];
    fgets(input, sizeof(input), stdin);
    longnonrepeat(input);
    return 0;
}
