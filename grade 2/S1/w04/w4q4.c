#include <stdio.h>
#include <string.h>

int main()
{
//    int n;
//    while(scanf("%d",&n),n!=0)
//    {
//        if(n%11==0)
//            printf("%s is a multiple of 11.\n", n);
//        else
//            printf("%s is not a multiple of 11.\n", n);
//    }
//=======================================================================

    char n[1001];
    while(1)
    {
        scanf("%s",n);
        if(n[0]=='0' && strlen(n)==1)
        {
            break;
        }
        int length=strlen(n);
        int odd=0,even=0;
        for(int i=0; i<length; i++)
        {
            if(i%2==0)
                even+=n[i]-'0';
            else
                odd+=n[i]-'0';
        }
//        printf("©_¼Æ is %d, °¸¼Æ is %d.\n", odd,even);
        int dif=odd-even;
//        if(dif%11==0)
//            printf("%s is a multiple of 11.\n", n);
//        else
//            printf("%s is not a multiple of 11.\n", n);
    }


    return 0;
}
