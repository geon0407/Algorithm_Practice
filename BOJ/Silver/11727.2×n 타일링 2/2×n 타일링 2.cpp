#include <bits/stdc++.h> 
using namespace std;

int DP[1010];

int main(void)
{
    int n, i;
    scanf("%d", &n);

    DP[0] = DP[1] = 1;
    for(i=2;i<=n;i++) {
        DP[i] = (DP[i-1] + DP[i-2] * 2) % 10007;
    }

    printf("%d\n", DP[n] % 10007);
    return 0;
}
