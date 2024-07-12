#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int minions[n][m];
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        minions[x - 1][y - 1] = 1;
    }

    long long dp[n][m];
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++) 
        {
            dp[i][j] = 0;

            if (!minions[i][j]) {
                if (i - 2 >= 0 && j - 1 >= 0) 
                    dp[i][j] += dp[i - 2][j - 1];
                
                if (i - 1 >= 0 && j - 2 >= 0) 
                    dp[i][j] += dp[i - 1][j - 2];
                    
                dp[i][j] %= MOD;
            }
        }
    }

    long long max_paths = 0;
    int max_column = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i][m - 1] > max_paths) {
            max_paths = dp[i][m - 1];
            max_column = i + 1;
        }
    }

    printf("%d %lld\n", max_column, max_paths);

    return 0;
}