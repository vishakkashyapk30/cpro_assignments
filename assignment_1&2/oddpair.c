#include <stdio.h>
int main()
{
    /*int n,count=0,k;
    scanf("%d\n",&n);

    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d ", &arr[i]);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            count++;
        }
        if(count==0 || count%2 == 1)
        k=arr[i];
        count=0;
    }
    printf("%d",k);
    return 0;*/
    int n;
    scanf("%d", &n);
    int xor=0;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        xor^=num;
    }
    printf("%d",xor);
    return 0;
}











