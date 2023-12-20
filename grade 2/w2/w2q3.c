#include <stdio.h>

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a>b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (c>d)
    {
        int temp = c;
        c = d;
        d = temp;
    }
    //printf("%d%d%d%d\n",a,b,c,d);
    if(c<b || d<a)
    {
        printf("overlay");
    }
    else printf("no overlay");
    return 0;
}

