#include <stdio.h>
int main(){
    int n,x,y,sum;
    scanf("%d %d %d", &n,&x,&y);
    printf("%d %d ", x,y);
    for(int i=1;i<=n-2;i++){
        sum=x+y;
        printf("%d ",sum);
        x=y;
        y=sum;
    }
}
   