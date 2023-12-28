#include <stdio.h>
#include <math.h>

int main(){
    float off,down,n;
    scanf("%f",&n);
    down=round(n*100)/100;
    off=floor(n*100)/100;
    printf("%.2f\n%.2f",down,off);

    return 0;
}
