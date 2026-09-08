#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long n;
    scanf("%lld", &n);

    int cnt=1;
    long long r=1, tmp=1;
    while( 1 ) {
        if(r >= n) {
            break;
        }
        tmp = 6 * (cnt++);
        r += tmp;
    }

    printf("%d", cnt);
    return 0;
}
