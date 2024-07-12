#include <stdio.h>
int main()
{
    int n,count;
    scanf("%d",&n);
    if(n==2)
    {
        printf("2");
    }
    else if(n>2)
    {
        for(int i=2;i<=n;i++)
        {
            count=0;
            for(int j=2;j<=i/2;j++)
            {
                if(i%j==0)
                {
                count++;
                break;
                }
            }
            if(count==0)
            printf("%d ",i);
        }
    }
    return 0;
}