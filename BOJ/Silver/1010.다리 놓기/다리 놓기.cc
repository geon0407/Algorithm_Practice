#include <bits/stdc++.h>
using namespace std;

int f(int n, int r);

int dp[50][50];
int n;

int main(void)
{
    scanf("%d", &n);

    while(n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", f(b, a));
    }

    return 0;
}

int f(int n, int r)
{
    if(n == r || r == 0) {
        return 1;
    }
    if(dp[n][r]) {
        return dp[n][r];
    }
    return dp[n][r] = f(n-1, r-1) + f(n-1, r);
}
