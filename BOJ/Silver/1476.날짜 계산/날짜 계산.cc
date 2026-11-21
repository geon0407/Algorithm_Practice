#include <bits/stdc++.h>
using namespace std;

int calc();

int e, m, s;

int main(void)
{
    scanf("%d%d%d", &e, &m, &s);
    printf("%d\n", calc());
    return 0;
}

int calc()
{
    int ans=0;
    while( 1 ) {
        ans++;
        if((ans - e) % 15 == 0 && (ans - m) % 28 == 0 && (ans - s) % 19 == 0) {
            return ans;
        }
    }
}
