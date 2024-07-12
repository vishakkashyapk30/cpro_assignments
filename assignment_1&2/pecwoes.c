#include <stdio.h>

int main() {
    int n;
    int arr[100][100] = {0};
    scanf("%d", &n);
    int a[n], b[n], c[n], d[n];
    
    for(int i=0;i<n;i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }

    for(int i=0;i<n;i++) {
        for(int j=a[i]; j<b[i]; j++) {
            for(int k=c[i]; k<d[i]; k++) 
                arr[j][k] = 1;
        }
    }

    int area=0;

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(arr[i][j] == 1)
                area++;
        }
    }

    printf("%d\n", area);
    return 0;
}