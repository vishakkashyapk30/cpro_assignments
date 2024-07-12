#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char s[n];
    scanf("%s", s);

    char c[n];
    memset(c, 'a', sizeof(c));

    

    for(int i = 0; i < n; i++) {
        int sum=0;
        if(s[i]>c[i])
            sum+=s[i]-c[i];
        else 
            sum+=c[i]-s[i];
        if(k>sum)
            k-=sum;
        else if(k<sum)
            break;
        if(k==0)
            break;
    }

    if(k>0){
        for(int i=n-1;i>=0;i--){
            if(s[i]>='n' && s[i]<='z'){
               continue;
            }
            else if(s[i]>='a' && s[i]<='m'){
                if(k>='z'-s[i]+1){
                    c[i]='z';
                    k-=('z'-s[i]+1);
                    continue;
                }
                else{
                    int d=s[i]-c[i];
                    k+=d;
                    c[i]=s[i]+k;
                    k=0;
                    break;
                }
            }
        }
    }

    if(k>0)
        printf("-1");
    else
        printf("%s\n", c);

    return 0;
}