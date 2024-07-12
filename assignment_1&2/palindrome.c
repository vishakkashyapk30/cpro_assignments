#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    
    int flag=0,count=0;

    for(int i=0;i<n/2;i++){
        for(int j=i;j<=n/2;j++){
            if(arr[j]!=arr[n-1-j])
                flag=1;
                break;
        }
        if(flag==0)
            count++;
    }
    printf("%d", n+count);

    return 0;
}