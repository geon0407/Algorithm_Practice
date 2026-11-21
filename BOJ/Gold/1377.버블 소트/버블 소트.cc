#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    
    vector<pair<int, int>> a(n);
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    
    int ans=0;
    for(int i=0;i<n;i++) {
        ans = max(ans, a[i].second - i);
    }
    
    printf("%d\n", ans+1);
    return 0;
}