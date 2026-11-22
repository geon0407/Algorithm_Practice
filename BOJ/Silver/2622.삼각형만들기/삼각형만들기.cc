#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long int ans = 0;
    int n, i;
    scanf("%d", &n);

    for(i=n/3+(n%3!=0);i<n/2+n%2;i++) {
        ans += i - ((n-i) / 2 + (n - i) % 2) + 1;
    }

    printf("%lld\n", ans);
    return 0;
}