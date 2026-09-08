#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> data;
int n, m;

int main(void)
{
    int i, ans=0;
    scanf("%d%d", &n, &m);

    if(m == 0) {
        printf("%d\n", n);
        exit(0);
    }

    for(i=0;i<m;i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        data.push_back(pair<int, int>(x, y));
    }
    sort(data.begin(), data.end());

    vector<pair<int, int>>::iterator it;
    int st, fi;
    ans = data[0].first;
    st = data[0].first;
    fi = data[0].second;
    for(it=data.begin()+1;it!=data.end();it++) {
        if(it->first <= fi) {
            fi = max(fi, it->second);
        }
        else {
            ans += it->first - fi;
            st = it->first;
            fi = it->second;
        }
    }
    ans += n - fi;
    printf("%d\n", ans);
    return 0;
}
