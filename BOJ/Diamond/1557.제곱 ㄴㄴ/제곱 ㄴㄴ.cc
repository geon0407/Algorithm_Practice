#include <bits/stdc++.h>
using namespace std;

int mob[100010];

long long calc(long long n)
{
    int i;
    long long ans=0;

    for(i=1;i*i<=n;i++) {
        ans += mob[i] * (n/(i*i));
    }

    return ans;
}

int main(void)
{
    int i, j, k;
    scanf("%d", &k);
    fill(mob+1, mob+100001, 1);

    for(i=2;i*i<=100000;i++) {
        if(mob[i] == 1) {
            for(j=i;j<=100000;j+=i) {
                mob[j] *= -i;
            }
            for(j=i*i;j<=100000;j+=i*i) {
                mob[j] = 0;
            }
        }
    }
    for(i=2;i<=100000;i++) {
        if(mob[i] == i) {
            mob[i] = 1;
        }
        else if(mob[i] == -i) {
            mob[i] = -1;
        }
        else if(mob[i] < 0) {
            mob[i] = 1;
        }
        else if(mob[i] > 0) {
            mob[i] = -1;
        }
    }

    long long st, fi;
    st = 1;
    fi = 2000000000;
    while(st < fi) {
        long long mid = (st + fi) >> 1;
        long long val = calc(mid);

        if(val > k) {
            fi = mid - 1;
        }
        else if(val == k) {
            fi = mid;
        }
        else {
            st = mid + 1;
        }
    }

    printf("%lld\n", fi);
    return 0;
}