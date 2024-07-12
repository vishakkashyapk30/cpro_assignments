#include <stdio.h>
#include <string.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    char S[N + 1];
    scanf("%s", S);

    int hFactor = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        int count = 0, maxCount = 0;
        for (int j = 0; j < N; j++)
        {
            if (S[j] == c)
            {
                count++;
                if (count == K)
                {
                    maxCount++;
                    count = 0;
                }
            }
            else
                count = 0;
        }
        if (maxCount > hFactor)
            hFactor = maxCount;
    }
    printf("%d\n", hFactor);
    return 0;
}
