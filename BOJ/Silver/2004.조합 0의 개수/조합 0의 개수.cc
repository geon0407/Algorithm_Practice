#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> f(long long n);

int main(void)
{
    long long n, m;
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", min(f(n).first-f(m).first-f(n-m).first , f(n).second-f(m).second-f(n-m).second));
    return 0;
}

pair<long long, long long> f(long long n)
{
    long long t=0, f=0;

    for(long long i=2;i<=n;i*=2) {
        t += n / i;
    }
    for(long long i=5;i<=n;i*=5) {
        f += n / i;
    }

    return make_pair(t, f);
}
