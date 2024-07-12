#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char str[n];
    scanf("%s", str);

    char ctr[n];
    int s = 0;

    for (int i = 0; i < n; i++) {
        int t = str[i] - 'a';
        int h = 'z' - str[i];

        if (t > h) {
            s += t;
        } else {
            s += h;
        }
    }

    if (s < k) {
        printf("-1\n");
    } else {
        strcpy(ctr, str);

        for (int i = 0; i < n; i++) {
            int sub = str[i] - 'a';

            if (sub >= k) {
                ctr[i] = str[i] - k;
                k = 0;
                break;
            } else {
                ctr[i] = str[i] - sub;
                k -= sub;
            }
        }

        if (k > 0) {
            for (int i = n - 1; i >= 0; i--) {
                int m = str[i] - 'a';
                int o = 'z' - str[i];

                if ((o - m) >= k) {
                    ctr[i] = ctr[i] + 2 * m + k;
                    k = 0;
                    break;
                } else if ((o - m) > 0) {
                    ctr[i] = 'z';
                    k -= (o - m);
                }
            }
        }

        printf("%s\n", ctr);
    }

    return 0;
}
