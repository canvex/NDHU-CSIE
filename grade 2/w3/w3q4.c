#include <stdio.h>
int main(void)
{
    int n, arr[4];
    _Bool have4 = 0;
    scanf("%d", &n);
    for (int i = 0; i < 4; i++)
    {
        arr[i] = n % 10;
        n /= 10;
    }

    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == 4)
            have4 = 1;
    }
    if (have4)
        printf("Yes");
    else
        printf("No");
    return 0;
}
