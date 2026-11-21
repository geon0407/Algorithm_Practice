#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long n, ans;
    scanf("%lld", &n);

    ans = 1 + 4 * n + 3 * n * (n-1) / 2;
    ans %= 45678;

    printf("%lld\n", ans);
    return 0;
}
