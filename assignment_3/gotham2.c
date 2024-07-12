#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAXN 1005

int dp[MAXN][MAXN];
int minions[MAXN][MAXN];

int dx[] = {1, 1, 2, 2};
int dy[] = {2, -2, 1, -1};

int n, m, k;

int isValid(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m && !minions[x][y]);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    memset(dp, 0, sizeof(dp));
    memset(minions, 0, sizeof(minions));
 
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        minions[x][y] = 1;
    }

    for (int j = 1; j <= m; j++) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i - dx[k];
                int y = j - dy[k];
                if (isValid(x, y)) {
                    dp[i][j] = (dp[i][j] + dp[x][y]) % MOD;
                }
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        printf("%d ", dp[n][i]);
    }
    printf("\n");

    return 0;
}
