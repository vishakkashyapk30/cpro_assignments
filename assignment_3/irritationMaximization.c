#include <stdio.h>
#include <stdlib.h>

long long maxIrritation(int n, int *x){
    long long *currentIrritation = (long long *)malloc((n + 1) * sizeof(long long));
    long long maxIrritation = 0;

    for (int i = n; i >= 1; i--){
        currentIrritation[i]=x[i-1]; 
        if (i+x[i-1]<=n){
            currentIrritation[i]+=currentIrritation[i+x[i - 1]];
        }

        if(currentIrritation[i]>maxIrritation) 
            maxIrritation=currentIrritation[i];
        
        else if(currentIrritation[i]<=maxIrritation)
            maxIrritation=maxIrritation;
    }

    free(currentIrritation);

    return maxIrritation;
}

int main() {
    int t;
    scanf("%d", &t);

    int temp=t;
    long long result[t];

    while(t--){
        int n;
        scanf("%d", &n);

        int *x = (int *)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++){
            scanf("%d", &x[i]);
        }
        result[t]=maxIrritation(n, x);
        free(x);
    }

    for(int i=temp-1;i>=0;i--)
        printf("%lld\n", result[i]);

    return 0;
}
