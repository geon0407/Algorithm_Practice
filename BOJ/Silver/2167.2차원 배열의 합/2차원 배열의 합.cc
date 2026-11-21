#include <bits/stdc++.h>
using namespace std;

int dp[310][310];
int n, m;

int main(void) {
    int i, j;
    scanf("%d%d", &n, &m);
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            int in;
            scanf("%d", &in);
            dp[i][j] = in + dp[i][j-1] - dp[i-1][j-1] + dp[i-1][j];
        }
    }

    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", dp[c][d] - dp[c][b-1] - dp[a-1][d] + dp[a-1][b-1]);
    }

    return 0;
}