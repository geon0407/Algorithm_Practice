#include <bits/stdc++.h> 
using namespace std;

int dp[50010];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        dp[i] = 4;
    }

    for(int i=1;i<=sqrt(n);i++) {
        dp[i*i] = 1;
    }

    for(int i=2;i<=n;i++) {
        if(dp[i] != 4) {
            continue;
        }

        int j = 1;
        while(j*j <= i) {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
            j++;
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
