#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int arr[n][n],temp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &arr[i][j]);
            temp[i][j]=arr[i][j];
        }
    }

    int d;
    scanf("%d", &d);

    //For clockwise
    if(d==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    if(j==0)
                        arr[i][j]=temp[i+1][j];
                    else
                        arr[i][j]=temp[i][j-1];
                }
                else if(i==n-1){
                    if(j==n-1)
                        arr[i][j]=temp[i-1][j];
                    else
                        arr[i][j]=temp[i][j+1];
                }
                else if(j==0 && i!=0 && i!=n-1){
                    arr[i][j]=temp[i+1][j];
                }
                else if(j==n-1 && i!=0 && i!=n-1){
                    arr[i][j]=temp[i-1][j];
                }
            }
        }
    }

    //For anti-clockwise
    if(d==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    if(j==n-1)
                        arr[i][j]=temp[i+1][j];
                    else
                        arr[i][j]=temp[i][j+1];
                }
                else if(i==n-1){
                    if(j==0)
                        arr[i][j]=temp[i-1][j];
                    else
                        arr[i][j]=temp[i][j-1];
                }
                else if(j==0 && i!=0 && i!=n-1){
                    arr[i][j]=temp[i-1][j];
                }
                else if(j==n-1 && i!=0 && i!=n-1){
                    arr[i][j]=temp[i+1][j];
                }
            }
        }
    }
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}