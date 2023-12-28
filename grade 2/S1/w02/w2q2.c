#include <stdio.h>

int main()
{
    int n,ans;
    scanf("%d",&n);
    for(int i=0; i<4; i++)
    {
        ans=ans*10+n%10;
        n/=10;
    }
    if(ans<1000){
        printf("0%d",ans);//如果最後一個數是0，前面補0
    }else
    printf("%d",ans);
    return 0;
}
