#include <stdio.h>
#include <string.h>

int isStringBeautiful(char str[], int length){

    int characters[52]={0}, flag=0, flag1=0, flag2=0, index, sameLetter=1;
    
    for(int i=0;i<length;i++){
        char c=str[i];
        if(c>='A' && c<='Z'){
            flag1=1;
            index = c-'A';
        }
    
        else if(c>='a' && c<='z'){ 
            flag2=1;
            index = c-'a'+26;
        }

        else{
            continue;
        }
        
        if(characters[index]){
            sameLetter=0;
            break;
        }
        
        characters[index]=1;
    }
    
    return flag1 && flag2 && sameLetter;
}

int main(){
    char ch[100];
        scanf("%s", ch);

    if(isStringBeautiful(ch, strlen(ch)))
        printf("Yes");
    else 
        printf("No");
    
    return 0;
}