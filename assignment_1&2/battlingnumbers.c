#include <stdio.h>
#include <math.h>
int main(){
    int N,M;
    scanf("%d",&N);
    int A[N],B[N];
    for(int i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d", &B[i]);
    }
    scanf("%d", &M);
    int C[M],D[M];
    for(int i=0;i<M;i++){
        scanf("%d", &C[i]);
    }
    for(int i=0;i<M;i++){
        scanf("%d", &D[i]);
    }
    int X=1,Y=1;
    for(int i=0;i<N;i++){
        X*=(int)pow(A[i],B[i]);
    }
    for(int i=0;i<M;i++){
        Y*=(int)pow(C[i],D[i]);
    }
    return 0;
}