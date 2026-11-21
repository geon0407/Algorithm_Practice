#include <bits/stdc++.h>
using namespace std;

long long power[1000010];
bool res[1000010];

int main(void)
{
    long long M, m, i;
    scanf("%lld %lld", &m, &M);

    long long sq = (long long)sqrt(M);
    long long cnt = 0;
    for(i=2;i<=sq;i++) {
        power[i] = i*i;
        cnt++;
    }

    int ans=0;
    for(i=2;i<cnt+2;i++) {
        long long div = m;
        if(div % power[i] != 0) {
            div = ((m/power[i]) + 1) * power[i];
        }

        long long j;
        for(j=div;j<=M;j+=power[i]) {
            if(!res[j-m]) {
                res[j-m] = true;
                ans++;
            }
        }
    }

    printf("%lld\n", M-m-ans+1);
    return 0;
}
