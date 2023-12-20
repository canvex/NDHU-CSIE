#include <stdio.h>
#include <string.h>
int main(){
    int m,n,c;
    int row,col,val;
    scanf("%d%d%d",&m,&n,&c);
    int arr[m][n];
    memset(arr,0,sizeof(arr)); //預設陣列值為0

    for(int i=0;i<c;i++){
        scanf("%d%d%d",&row,&col,&val); //輸入不為0的值
        arr[row][col]=val;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);// 印出
        }
        printf("\n");
    }

return 0;}
