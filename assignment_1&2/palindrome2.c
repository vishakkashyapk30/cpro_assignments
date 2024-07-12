#include <stdio.h>

int main() {
    int n, count=0;
    scanf("%d", &n);

    int arr[n];
    for (int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){

            int left=i,right=j,flag=0;

            while(left<right){
                if(arr[left]!=arr[right]){
                    flag=1;
                    break;
                }
                left++;
                right--;
            }
            if(flag==0)
                count++;
        }
    }
    printf("%d\n", count);

    return 0;
}
