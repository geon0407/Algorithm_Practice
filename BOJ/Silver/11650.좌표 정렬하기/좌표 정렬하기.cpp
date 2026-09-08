#include <bits/stdc++.h>
using namespace std;

pair<int, int> p[100010];

int main(void)
{
    int i, n;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p, p+n);
    for(i=0;i<n;i++) {
        printf("%d %d\n", p[i].first, p[i].second);
    }
    return 0;
}
