#include <stdio.h>
int main()
{
    char c;
    scanf("%c",&c);
    //%d��XASCII�ȡA%c��X�r��
    printf("%d\n%c", c,c);
    return 0;
}
