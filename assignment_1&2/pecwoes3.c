#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],b[n],c[n],d[n];
    for(int i=0;i<n;i++)
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
    
    int x[102]={0},y[102]={0};

    for(int i=0;i<n;i++){
        for(int j=a[i];j<b[i];j++)
            x[j]=1;
        for(int j=c[i];j<d[i];j++)
            y[j]=1;
    }

    int count=0;

    for(int i=0;i<102;i++)
    {
        if(x[i]==1 && x[i+1]==1)
        {
            for(int j=0;j<102;j++)
            {
                if(y[j]==1 && y[j+1]==1)
                {
                    count++;
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}