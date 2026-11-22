#include <bits/stdc++.h>

#define LIMIT 987654321

using namespace std;

int cmp(const pair<int, int> &p, const pair<int, int> &q)
{
    if(p.first != q.first) {
        return p.first < q.first;
    }

    return p.second > q.second;
}

int LIS(const vector< pair<int, int> > &a)
{
    int i;

    vector< pair<int, int> > b;
    vector< pair<int, int> >::iterator lo;

    for(i=0;i<(int)a.size(); i++) {
        lo = lower_bound(b.begin(), b.end(), make_pair(-a[i].second, LIMIT));
        if(lo == b.end()) {
           b.push_back(make_pair(-a[i].second, 1));
        }
        else {
            *lo = make_pair(-a[i].second, 1);
        }
    }

    return b.size();
}

int main(void)
{
    int n, i;

    scanf("%d", &n);

    vector< pair<int, int> > a(n);
    for(i=0;i<n;i++) {
        scanf("%*d %d %d", &a[i].first, &a[i].second);
    }
    
    sort(a.begin(), a.end(), cmp);
    a.erase(unique(a.begin(), a.end()), a.end());

    printf("%d\n", LIS(a));
    return 0;
}
