#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    long long lan[10010];
    long long l=1, h=0, ans=0;
    int k, n;
    cin >> k >> n;
    for(int i=0;i<k;i++) {
        cin >> lan[i];
        h = max(h, lan[i]);
    }

    while(h >= l) {
        long long m = (l + h) / 2;
        int res = 0;
        for(int i=0;i<k;i++) {
            res += lan[i] / m;
        }

        if(res >= n) {
            ans = max(ans, m);
            l = m + 1;
        }
        else {
            h = m - 1;
        }
    }

    cout << ans;
    return 0;
}
