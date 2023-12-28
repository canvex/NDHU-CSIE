#include <stdio.h>
int main(void)
{
    int arr[4],tmp;
    for(int i=0; i<4; i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0; i<4; i++)
    {
        for(int j=i+1; j<4; j++)
        {
            if(arr[i]>arr[j])
            {
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }

    printf("%d\n",arr[3]);

    for(int i=0; i<4; i++)
    {
        //printf("%d ",arr[i]);
    }

    return 0;
}
