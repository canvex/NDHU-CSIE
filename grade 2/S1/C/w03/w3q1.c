#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    if (n % 3 == 2 || n % 7 == 5 || n % 11 == 7) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
