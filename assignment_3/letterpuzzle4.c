#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool COMP(char permute1[], char permute2[], int n){
	for (int i = 0; i < n; i++){
		if (permute1[i] != permute2[i])
			return false;
	}
	return true;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void generatePermutations(char *str, int start, int end, char **permutations, int *count) {
    if (start == end){
        permutations[*count] = strdup(str);
        (*count)++;
    }

	else{
        for (int i = start; i <= end; i++) {
            swap(&str[start], &str[i]);
            generatePermutations(str, start + 1, end, permutations, count);
            swap(&str[start], &str[i]);
        }
    }
}

int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char str[10];
    scanf("%s", str);

    int n = strlen(str);
    char **permutations = (char**) malloc(sizeof(char *) * 40320);
    int count = 0;

    generatePermutations(str, 0, n - 1, permutations, &count);

    qsort(permutations, count, sizeof(char *), compareStrings);

	int c1=1;

    for (int i = 1; i < count; i++)
	{
		if(COMP(permutations[i],permutations[i-1],n)==false)
			c1++;
    }

	printf("%d\n",c1);

	printf("%s\n",permutations[0]);

	for(int i=1;i<count;i++)
    {
		if(COMP(permutations[i],permutations[i-1],n)==false)
			printf("%s\n",permutations[i]);
	}
	
    free(permutations);
    return 0;
}