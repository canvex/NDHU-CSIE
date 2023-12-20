#include <stdio.h>

int main()
{
    int n,i,count=0;
    float avg=0;

    scanf("%d", &n);
//    if (n <= 0)
//    {
//        return 1;
//    }
    float data[n]; // 假設要存儲整數資料

    for(i =0; i<n; i++)
    {
        scanf("%f", &data[i]);
        avg+=data[i];
    }

//    printf("%f\n",avg/=n);
//    if (n != 0)
//    {
        avg /= n;
        for (i = 0; i < n; i++)
        {
            if(data[i]<avg)
                count++;
        }
//    }
    printf("%d",count);
    return 0;
}
