#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    char s[n+1];
    scanf("%s", s);

    bool inQuote=false;

    char result[n+1];
    strcpy(result, s);

    for(int i=0;i<n;i++){
        if(s[i]=='"')
            inQuote=!inQuote;

        if(s[i]==',' && !inQuote)
            result[i]='*';
    }

    printf("%s", result);

    return 0;
}