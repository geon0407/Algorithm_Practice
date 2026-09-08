#include <bits/stdc++.h>
using namespace std;

int t[1010];

int main(void)
{
    int n, i, ans=0;
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        scanf("%d", &t[i]);
    }
    sort(t+1, t+n+1);
    
    for(i=1;i<=n;i++) {
        t[i] = t[i-1] + t[i];
        ans += t[i];
    }
    
    printf("%d\n", ans);
    return 0;
}
