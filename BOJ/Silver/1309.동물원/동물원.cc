#include <bits/stdc++.h>
using namespace std;

int dp[10][100010];
int n;

int main(void)
{
    int i;
    scanf("%d", &n);

    dp[0][1] = dp[1][1] = dp[2][1] = 1;

    for(i=2;i<=n;i++) {
        dp[0][i] = (dp[0][i-1] + dp[1][i-1] + dp[2][i-1]) % 9901;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % 9901;
        dp[2][i] = (dp[0][i-1] + dp[1][i-1]) % 9901;
    }

    printf("%d\n", (dp[0][n] + dp[1][n] + dp[2][n]) % 9901);
    return 0;
}