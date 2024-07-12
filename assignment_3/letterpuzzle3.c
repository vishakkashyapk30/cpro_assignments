#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to swap two characters in a string
void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate permutations and print them in lexicographical order
void generatePermutations(char *str, int left, int right, char **permutations, int *count) {
    if (left == right) {
        permutations[*count] = strdup(str);
        (*count)++;
    } else {
        for (int i = left; i <= right; i++) {
            swap(&str[left], &str[i]);
            generatePermutations(str, left + 1, right, permutations, count);
            swap(&str[left], &str[i]);  // backtrack
        }
    }
}

int main() {
    char str[9];
    scanf("%s", str);

    int len = strlen(str);
    char **permutations = (char **)malloc(len * len * sizeof(char *));
    int count = 0;

    generatePermutations(str, 0, len - 1, permutations, &count);

    // Sort the permutations in lexicographical order
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(permutations[i], permutations[j]) > 0) {
                char *temp = permutations[i];
                permutations[i] = permutations[j];
                permutations[j] = temp;
            }
        }
    }

    // Print the number of strings
    printf("%d\n", count);

    // Print the strings in alphabetical order
    for (int i = 0; i < count; i++) {
        printf("%s\n", permutations[i]);
        free(permutations[i]);
    }

    free(permutations);
    return 0;
}
