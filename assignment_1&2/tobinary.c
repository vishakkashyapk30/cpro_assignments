#include <stdio.h>
int main(){
    /*int num,temp=0,sum=0,a=1;
    scanf("%d", &num);
    if(num==0)
    printf("0");
    else if(num>0){
        while(num>0){
            temp=num%2;
            num/=2;
            sum+=temp*a;
            a*=10; 
        }
    }
    printf("%d", sum);*/
    int num,count;
    scanf("%d",&num);
    int temp=num;
    if(num==0)
    printf("0");
    while(num>0){
        num/=2;
        count++;
    }
    for(int i=count-1;i>=0;i--){
        if(temp&(1<<i)!=0)
        printf("1");
        else printf("0");
    }
    return 0;
}