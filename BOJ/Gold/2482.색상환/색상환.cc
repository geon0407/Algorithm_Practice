#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000003;

int n, k;
int dp[1003][1003];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    if(k == 1) {
        cout << n;
        return 0;
    }

    if(k > n/2) {
        cout << 0;
        return 0;
    }

    for(int i=0;i<=n;i++) {
        dp[i][0] = 1;
    }

    for(int i=1;i<=n;i++) {
        dp[i][1] = i;
    }

    for(int i=2;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
        }
    }

    int answer = (dp[n][k] - dp[n-4][k-2] + MOD) % MOD;
    cout << answer;

    return 0;
}