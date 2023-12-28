#include <stdio.h>
#include <math.h>

int main()
{
    int n,i,count=0;
    float avg,avg2,ans;

    scanf("%d", &n);
    float data[n]; // 假設要存儲整數資料

    for(i =0; i<n; i++)
    {
        scanf("%f", &data[i]);
        avg+=data[i];
    }

    avg /= n;

    for (i = 0; i < n; i++)
    {
        avg2+=pow(data[i]-avg,2);
    }
    ans=sqrt(avg2/=n);
    printf("%.2f",ans);
    return 0;
}
