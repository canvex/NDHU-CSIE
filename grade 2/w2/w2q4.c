#include <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a+b<=c)
    {
        printf("%s","can not construct");
    }
    else
    {
        if(a*a+b*b==c*c)
        {
            printf("%s","right triangle");
        }
        else if(a*a+b*b>c*c)
        {
            printf("%s","acute triangle");
        }
        else if(a*a+b*b<c*c)
            printf("%s","obtuse triangle");
    }
    //printf("%d",c);
    return 0;
}
