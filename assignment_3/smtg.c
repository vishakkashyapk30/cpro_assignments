#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 27
#define A 26

bool anagram(char *str1, char *str2, int len){
    int arr1[N]={0};
    int arr2[N]={0};

    for(int i=0;i<len;i++){
        if(str1[i]=='@')
            arr1[A]++;
        else 
            arr1[str1[i]-'a']++;
        if(str2[i]=='@')
            arr2[A]++;
        else 
            arr2[str2[i]-'a']++;
    }

    int m1=0,m2=0;
    for(int i=0;i<7;i++){
        if(arr1[i]!=arr2[i]){
            if(arr1[i]<arr2[i])
                m1+=(arr2[i]-arr1[i]);
            else 
                m2+=(arr1[i]-arr2[i]);
        }
    }

    if(m1>arr1[A] || m2>arr2[A])
        return false;
    
    for(int i=7;i<A;i++){
        if(arr1[i]!=arr2[i])
            return false;
    }

    return true;
}

int main(){
    int t;
    scanf("%d", &t);

    int result[t];

    for(int i=0;i<t;i++){
        int n;
        scanf("%d", &n);
        
        char s[n+1], c[n+1];
        scanf("%s", s);
        scanf("%s", c);

        result[i]=anagram(s, c, n);
    }

    for(int i=0;i<t;i++)
        printf("%s", (result[i] == 1)?"Yes\n":"No\n");

    return 0;
}