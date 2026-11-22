#include <bits/stdc++.h>
using namespace std;

long long int n;
long long int DP[1500010];

int main(void)
{
    int i;
    scanf("%lld", &n);
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 1;

    if(n <= 2) {
        printf("%lld\n", DP[n]);
        exit(0);
    }

    for(i = 3; i <= 1500000; i ++) {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 1000000;
    }

    printf("%lld\n", DP[n % 1500000]);
    return 0;
}