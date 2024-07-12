#include <stdio.h>
#include <stdlib.h>

int track(int *ans, int *a, int n, int k, int m){
    for(int i=1;i<=k && (n-1+i)<=m;i++){
        int t;
        t=abs(a[n-1+i]-a[n-1])+ans[n-1+i];
        if(ans[n-1]>t || ans[n-1]==-1)
            ans[n-1]=t; 
    }
    if(n==1)
        return ans[0];
    else
        return track(ans,a,n-1,k,m);
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n], ans[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        ans[i]=-1;
    }

    ans[n-1]=0;
    printf("%d", track(ans,a,n,k,n-1));

    return 0;
}