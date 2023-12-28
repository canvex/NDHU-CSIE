#include <stdio.h>

void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int ans(int s, int count) {
    count++;
    if (s % 2 == 0)
        return ans(s / 2, count);
    else if (s % 2 == 1 && s > 1)
        return ans(3 * s + 1, count);
    return count;
}

int main() {
    int a, b, n1, n2, count;
    while (scanf("%d%d", &n1, &n2) != EOF) {
        int max = 0;
        a = n1;
        b = n2;
        if (a > b)
            swap(&a, &b);
        for (int i = a; i <= b; i++) {
            // if (ans(i, 0) > max) {
            //     max = ans(i, 0);
            // }
            max = ans(i, 0) > max ? ans(i, 0) : max;
        }

        printf("%d %d %d\n", n1, n2, max);
    }

    return 0;
}