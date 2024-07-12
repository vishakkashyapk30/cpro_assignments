#include <stdio.h>
int main(){
    int num;
    scanf("%d",&num);

    if(num==0){
        printf("0");
    }
    int x=1<<30;
    int skip=0;

    while(x>0){
        if(num&x){
            skip=1;
            printf("1");
        }
        else if(skip){
            printf("0");
        }
        x>>=1;
    }
    return 0;
}