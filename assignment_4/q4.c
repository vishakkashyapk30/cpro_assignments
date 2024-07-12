#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    char s[1002];
    scanf("%s", s);

    int len = strlen(s);

    char sMax[len], sMin[len];
    strcpy(sMax, s);
    strcpy(sMin, s);  

    for(int i = 0; i < len; i++){
        char temp = s[len-1];
        for(int j = len-1; j > 0; j--){
            s[j] = s[j-1];
        }
        s[0] = temp;

        if(strcmp(s, sMax) > 0){
            strcpy(sMax, s);
        }
        
        if(strcmp(s, sMin) < 0){
            strcpy(sMin, s);
        }
    }

    printf("%s\n", sMin);
    printf("%s\n", sMax);

    return 0;
}
