#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 10

// Function to swap two characters in a string
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate all permutations of a string
void permute(char *str, int l, int r, char **words, int *count) {
    if (l == r) {
        strcpy(words[(*count)++], str);
    } else {
        for (int i = l; i <= r; i++) {
            swap(str + l, str + i);
            permute(str, l + 1, r, words, count);
            swap(str + l, str + i); // backtrack
        }
    }
}

int main() {
    char input[MAX_N];
    scanf("%s", input);
    
    int len = strlen(input);
    char **words = (char **)malloc(sizeof(char *) * (1 << len)); // Allocate memory for words
    for (int i = 0; i < (1 << len); i++) {
        words[i] = (char *)malloc(sizeof(char) * (len + 1)); // Allocate memory for each word
    }
    
    int count = 0;
    
    permute(input, 0, len - 1, words, &count);
    
    // Sort the generated words alphabetically
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char temp[MAX_N];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
    
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
        free(words[i]); // Free memory for each word
    }
    
    free(words); // Free memory for the array of words
    
    return 0;
}
