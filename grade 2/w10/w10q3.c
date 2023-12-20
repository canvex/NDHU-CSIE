#include <stdio.h>
#include <string.h>

typedef struct {
    char integer[1000];
    char decimal[1000];

} DeciVar;

int main() {
    DeciVar d[3] = {{0}};  // 初始化為空
    char input[1000];

    for (int i = 0; i < 2; i++) {
        scanf("%s", input);
        // 從陣列的第二個位置開始存儲
        strncpy(&d[i].integer[1], input, strlen(input));
        d[i].integer[0] = '0';
        // 使用 strchr 找到點號的位置
        char* dot_position = strchr(&d[i].integer[1], '.');
        // 將整數部分和小數部分分開存儲
        if (dot_position != NULL) {
            *dot_position = '\0';  // 在點號位置加上結束符號
            strcpy(d[i].decimal, dot_position + 1);
        } else {
            d[i].decimal[0] = '\0';  // 若沒有小數部分，則設為空字串
        }
    }

    // Calculating the sum of digits
    int length = 0;
    int int_length = 0;
    int carry = 0;
    int n = 0;
    // 找小數最長長度
    if (strlen(d[0].decimal) > strlen(d[1].decimal)) {
        length = strlen(d[0].decimal);
        n = strlen(d[0].decimal) - strlen(d[1].decimal);
        memset(d[1].decimal + strlen(d[1].decimal), '0', n);
    } else {
        length = strlen(d[1].decimal);
        n = strlen(d[1].decimal) - strlen(d[0].decimal);
        memset(d[0].decimal + strlen(d[0].decimal), '0', n);
    }

    // 找整數最長長度
    if (strlen(d[0].integer) > strlen(d[1].integer)) {
        int_length = strlen(d[0].integer);
        n = strlen(d[0].integer) - strlen(d[1].integer);
        memmove(d[1].integer + n, d[1].integer,
                int_length + 1);  // +1 是為了包含 null 結尾字元
        // 在前面補0
        memset(d[1].integer, '0', n);
        memset(d[2].integer, 0, int_length);
    } else {
        int_length = strlen(d[1].integer);
        n = strlen(d[1].integer) - strlen(d[0].integer);
        memmove(d[0].integer + n, d[0].integer,
                int_length + 1);  // +1 是為了包含 null 結尾字元
        // 在前面補0
        memset(d[0].integer, '0', n);
        memset(d[2].integer, 0, int_length);
    }
    // 處理小數
    for (int i = length - 1; i >= 0; i--) {  // 這裡減去1以防止越界
        if ((d[0].decimal[i] - '0' + d[1].decimal[i] - '0' + carry) >= 10) {
            d[2].decimal[i] +=
                ((d[0].decimal[i] - '0' + d[1].decimal[i] - '0' + carry) - 10) +
                '0';
            carry = 1;
        } else {
            d[2].decimal[i] +=
                ((d[0].decimal[i] - '0' + d[1].decimal[i] - '0' + carry)) + '0';
            carry = 0;
        }
    }
    // 檢查小數是否有進位
    if (carry == 1) {
        d[1].integer[int_length - 1]++;  // 整數最後一位+1
    }
    // 處理整數
    carry = 0;
    for (int i = int_length - 1; i >= 0; i--) {
        if ((d[0].integer[i] - '0' + d[1].integer[i] - '0' + carry) >= 10) {
            d[2].integer[i] +=
                ((d[0].integer[i] - '0' + d[1].integer[i] - '0' + carry) - 10) +
                '0';
            carry = 1;
        } else {
            d[2].integer[i] +=
                ((d[0].integer[i] - '0' + d[1].integer[i] - '0' + carry)) + '0';
            carry = 0;
        }
    }
    // 手動添加結束符號
    d[2].integer[int_length + 1] = '\0';

    // 找是否有小數
    int flag = 0;
    for (int i = 0; i < length; i++) {
        if (d[2].decimal[i] != '0') {  // 有小數
            flag = 1;
            break;
        }
    }
    // 找小數最後一個非0的位置
    int pos = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (d[2].decimal[i] != '0') {
            pos = i;
            break;
        }
    }
    d[2].decimal[pos + 1] = '\0';

    // 如果d[2].integer第一位是0，從第二位開始印
    char* integer;
    if (d[2].integer[0] == '0')
        integer = &d[2].integer[1];
    else
        integer = &d[2].integer[0];

    if (flag == 1) {
        printf("%s.%s\n", integer, d[2].decimal);
    } else {
        printf("%s\n", integer);
    }
    return 0;
}
