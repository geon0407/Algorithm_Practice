#include <bits/stdc++.h>
using namespace std;

string s;
long long MOD = 1234567891;

int main(void)
{
    long long ans = 0;
    int n;
    cin >> n >> s;

    long long r = 1;
    for(int i=0;i<n;i++) {
        ans = (ans + (s[i] - 96) * r) % MOD;
        r = (r * 31) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}
