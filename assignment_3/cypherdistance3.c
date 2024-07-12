#include <stdio.h>
#include <string.h>

int TotalChanges(char inputStr[], int n){
    int totalChanges = 0;

    for (int i = 0; i < n; i++) {
        int diffFromA = inputStr[i] - 'a';
        int diffFromZ = 'z' - inputStr[i];
        totalChanges += (diffFromA > diffFromZ) ? diffFromA : diffFromZ;
    }

    return totalChanges;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char inputStr[n+1];
    scanf("%s", inputStr);

    char outputStr[n+1];
    
    int totalChanges = TotalChanges(inputStr, n);

    if (totalChanges < k){
        printf("-1");
        return 0;
    }

    else if(totalChanges >= k){
        strcpy(outputStr, inputStr);

        for (int i = 0; i < n; i++){
            int subtractValue = inputStr[i] - 'a';

            if (subtractValue >= k){
                outputStr[i] = inputStr[i] - k;
                k = 0;
                break;
            } 
            
            else if(subtractValue<k){
                outputStr[i] = inputStr[i] - subtractValue;
                k -= subtractValue;
            }
        }

        if (k > 0){
            for (int i = n - 1; i >= 0; i--){
                if ((('z' - inputStr[i])-(inputStr[i] - 'a')) >= k) {
                    outputStr[i] = inputStr[i] + 2*(inputStr[i] - 'a') + k;
                    k = 0;
                    break;
                }
                else if ((('z' - inputStr[i])-(inputStr[i] - 'a')) > 0){
                    outputStr[i] = 'z';
                    k -= ('z' - inputStr[i]);
                }
            }
        }

        for(int i=0;i<n;i++)
            printf("%c", outputStr[i]);
    }

    return 0;
}
