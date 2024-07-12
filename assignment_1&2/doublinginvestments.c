#include <stdio.h>

int main(){

    int n,count=0;
    scanf("%d", &n);
    
    /*if(n==0)
        printf("0");
    
    else{
        while(n>1){
            if(n%2!=0){
                count++;
                n/=2;
            }
            else if(n%2==0){
                count=count;
                n=n/2;
            }   
        }
        printf("%d", count);
    }*/

    while(n>0){
        if(n%2==1)
            count++;
        n/=2;
    }
    
    printf("%d", count);

    return 0;
}