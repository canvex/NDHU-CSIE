#include <stdio.h>
#include <math.h>
int main(void)
{
    int n;
    double toll;
    scanf("%d",&n);
    if(n>200)
    {
        toll=(n-200)*1.2*0.75+200*1.2;
    }
    else
    {
        toll=n*1.2;
    }
    int roundedToll = round(toll);
    printf("%d\n",roundedToll);
    return 0;
}
