#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    vector<int> t;
    int n, m, ans, h=0, l=0;

    cin >> n >> m;
    t.resize(n);
    for(int i=0;i<n;i++) {
        cin >> t[i];
        h = max(h, t[i]);
    }

    while(h >= l) {
        long long res = 0;
        int mid = (l + h) / 2;

        for(auto tree : t) {
            res += max(0, tree - mid);
        }
        if(res >= (long long)m) {
            ans = mid;
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }

    cout << ans;
    return 0;
}
