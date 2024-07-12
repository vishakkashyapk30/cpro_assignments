#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 300010

void reverseString(char *str, int start, int end)
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char str[MAX_SIZE];
    scanf("%s", str);
    int len = strlen(str);

    int m;
    scanf("%d", &m);

    int totalReversals = 0;

    for (int i = 1; i <= m; i++)
    {
        int q;
        scanf("%d", &q);

        if (q == 1)
        {
            totalReversals++;
        }
        else if (q == 2)
        {
            int l;
            scanf("%d", &l);

            char c;
            scanf(" %c", &c);

            if (l == 1)
            {
                if (totalReversals % 2 == 0)
                {
                    for (int i = len; i > 0; i--)
                        str[i] = str[i - 1];
                    str[0] = c;
                    len++;
                    str[len] = '\0';
                }
                else
                {
                    str[len] = c;
                    len++;
                    str[len] = '\0';
                }
            }
            else if (l == 2)
            {
                if (totalReversals % 2 == 0)
                {
                    str[len + 1] = '\0';
                    str[len] = c;
                    len++;
                }
                else
                {
                    for (int i = len; i > 0; i--)
                        str[i] = str[i - 1];
                    str[0] = c;
                    len++;
                    str[len] = '\0';
                }
            }
        }
    }
    if (totalReversals % 2 == 1)
        reverseString(str, 0, len - 1);

    printf("%s\n", str);

    return 0;
}
