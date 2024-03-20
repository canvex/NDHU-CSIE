#include <stdio.h>
#include <string.h>

int main(void) {
    char input[1001];
    while (gets(input)) {
        int record[128] = {0};

        for (int i = 0; i < strlen(input); i++)
            record[input[i]]++;

        // 先顯示record次數最少的
        for (int i = 1; i <= 1001; i++)
            // 如果record次數相同，輸出ASCII碼比較大的
            for (int k = 127; k >= 32; k--)
                if (record[k] == i)
                    printf("%d %d\n", k, i);
        printf("\n");
    }

    return 0;
}
