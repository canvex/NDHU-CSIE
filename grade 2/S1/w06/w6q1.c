#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    // 1是質數，0不是質數
    int i;
    if (num == 1) {
        return 0;
    } else {
        for (i = 2; i < num; i++) {
            if (num % i == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int cmp(const void* a, const void* b) {
    int c = *(int*)a;  // 將指針轉換為整數
    int d = *(int*)b;
    if (is_prime(c) > is_prime(d))
        return -1;  // 如果C是質數D不是質數，c d
    if (is_prime(c) < is_prime(d))
        return 1;  // 如果C不是質數D是質數，d c
    if (is_prime(c) == is_prime(d) && is_prime(c) == 1) {  // 如果C跟D都是質數
        if (c > d)  // 大的放前面，小的放後面
            return -1;
        if (c < d)
            return 1;
    }
    if (is_prime(c) == is_prime(d) && is_prime(c) == 0) {  // 如果C跟D都不是質數
        if (c > d)  // 小的放前面，大的放後面
            return 1;
        if (c < d)
            return -1;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int ans[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ans[i]);
    }
    qsort(ans, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    // printf("answer %d", is_prime(12));
    return 0;
}