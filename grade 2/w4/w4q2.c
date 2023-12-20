#include <stdio.h>
int main()
{
    int n, temp;
    float ans;
    scanf("%d", &n);
    int data[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    // 註解

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (data[i] > data[j])
            {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    // data[0]=data[1]=data[2]=data[n-1]=data[n-2]=data[n-3]=0;
    for (int i = 3; i < n - 3; ++i)
    {
        // printf("%d, ", data[i]);
        ans += data[i];
    }
    ans /= (n - 6);
    printf("%.2f", ans);
    return 0;
}
