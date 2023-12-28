#include <stdio.h>

int F(int x) {
    return 3 * x + 1;
}
int G(int x, int y) {
    return x * y - 3;
}

int main() {
    char input[1000] = {0};
    char tmp[1000] = {0};
    fgets(input, 1000, stdin);
    // printf("%c", input[8]);
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ')') {
            int n1 = 0, n2 = 0;
            int has2 = 0;
            while (input[i] != 'F' || input[i] != 'G') {
                i--;
                if ((input[i] >= '0' && input[i] <= '9') && has2 == 0) {
                    n1 = input[i] - '0';
                    has2 = 1;
                }
                if ((input[i] >= '0' && input[i] <= '9') && has2 == 1) {
                    n2 = input[i] - '0';
                    has2 = 1;
                }
            }
            if (has2 == 1) {
                G(n2, n1);
            }
        }
    }

    return 0;
}