#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i*i <= n; i++) {
        printf("%d ", i*i);
    }
    return 0;
}
    /*int arr[n];
    //printf("i = 0 ");
    for(int i=0;i<n;i++){
        arr[i]=0;
        //printf("%d ", arr[i]);
    }

    //printf("\n");
    
    for(int i=1;i<=n;i++){
        //printf("i = %d ", i);
        for(int j=0;j<n;j++){
            if((j+1)%i==0){
                if(arr[j]==0)
                    arr[j]=1;
                else if(arr[j]==1)
                    arr[j]=0;
            }
            //printf("%d ", arr[j]);
        }
        //printf("\n");
    }

    for(int i=0;i<n;i++){
        if(arr[i]==1)
            printf("%d ", i+1);
    }*/
