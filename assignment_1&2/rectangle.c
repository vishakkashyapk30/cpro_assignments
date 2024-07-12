#include <stdio.h>
int main(){
    int width, height;
    scanf("%d %d", &width, &height);
    for(int i=1;i<=height;i++)
    {
        for(int j=1;j<=width;j++)
        {
            if((i==1&&j==1)||(i==1&&j==width)||(i==height&&j==1)||(i==height&&j==width))
            printf("o");
            else if((i!=1&&i!=height&&j==1)||(i!=1&&i!=height&&j==width))
            printf("|");
            else if((j!=1&&j!=width&&i==1)||(j!=1&&j!=width&&i==height))
            printf("-");
            else
            printf(" ");
        }
        printf("\n");
    }
}