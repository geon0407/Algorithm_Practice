#include <bits/stdc++.h>
using namespace std;

int dist(pair<int, int> p1, pair<int, int> p2);
int ans(vector<pair<int, int>> &p, int st, int fi);

const int intmax = numeric_limits<int>::max();
int n;

int main(void)
{
    vector<pair<int, int>> arr;

    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        arr.push_back(make_pair(x, y));
    }
    sort(arr.begin(), arr.end());

    printf("%d\n", ans(arr, 0, n-1));
    return 0;
}

int dist(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second);
}

int ans(vector<pair<int, int>> &p, int st, int fi)
{
    if(fi - st <= 2) {
        int res = intmax;
        for(int i=st;i<=fi;i++) {
            for(int j=i+1;j<=fi;j++) {
                res = min(res, dist(p[i], p[j]));
            }
        }

        return res;
    }

    int mid = (st + fi) / 2;
    int min_dist = min(ans(p, st, mid), ans(p, mid+1, fi));
    int cl = (p[mid].first + p[mid+1].first) / 2;

    vector<pair<int, int>> tmp;
    for(int i=st;i<=fi;i++) {
        int dx = p[i].first - cl;
        if(dx*dx < min_dist) {
            tmp.push_back(p[i]);
        }
    }
    sort(tmp.begin(), tmp.end(), [](pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    });

    int sz = tmp.size();
    for(int i=0;i<sz;i++) {
        for(int j=i+1;j<sz;j++) {
            int dy = tmp[i].second - tmp[j].second;
            if(dy*dy < min_dist) {
                min_dist = min(min_dist, dist(tmp[i], tmp[j]));
            }
            else {
                break;
            }
        }
    }

    return min_dist;
}
