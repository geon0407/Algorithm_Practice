#include <bits/stdc++.h>
using namespace std;

int ans;

int main(void)
{
    int i, n;
    scanf("%d%d", &n, &ans);
    for(i=1;i<n;i++) {
        int in;
        scanf("%d", &in);
        ans = ans - 1 + in;
    }
    printf("%d\n", ans);
    return 0;
}