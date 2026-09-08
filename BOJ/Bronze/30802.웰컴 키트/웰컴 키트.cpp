#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int sh[6];
    int n, t, p;
    scanf("%d", &n);
    for(int i=0;i<6;i++) {
        scanf("%d", &sh[i]);
    }
    scanf("%d%d", &t, &p);

    int T = 0;
    for(int i=0;i<6;i++) {
        T += (sh[i] + t - 1) / t;
    }

    printf("%d\n%d %d\n", T, n/p, n%p);
    return 0;
}
