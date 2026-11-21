#include <bits/stdc++.h>
using namespace std;

pair<int, int> l[1000010];
int n;

int main(void)
{
    int i, ans=0;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d%d", &l[i].first, &l[i].second);
    }

    sort(l, l+n);

    int st, fi;
    st = l[0].first;
    fi = l[0].second;
    for(i=1;i<n;i++) {
        if(fi >= l[i].first) {
            fi = max(fi, l[i].second);
        }
        else {
            ans += (fi - st);
            st = l[i].first;
            fi = l[i].second;
        }
    }
    ans += (fi - st);

    printf("%d\n", ans);
    return 0;
}