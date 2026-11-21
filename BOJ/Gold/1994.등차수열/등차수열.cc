#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
bool chk[2010][2010];

int n;

int main(void)
{
    int i, j;
    scanf("%d", &n);
    arr.resize(n);
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());

    int ans = 1;
    int cnt = 1;
    int cur = arr[0];
    for(i=1;i<n;i++) {
        if(arr[i] == cur) {
            cnt++;
        }
        else {
            ans = max(ans, cnt);
            cur = arr[i];
            cnt = 1;
        }
    }
    ans = max(cnt, ans);

    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    n = arr.size();
    for(i=0;i<arr.size();i++) {
        for(j=i+1;j<n;j++) {
            if(chk[i][j]) {
                continue;
            }

            chk[i][j] = true;
            int cnt = 2;
            int dif = arr[j] - arr[i];
            int val = dif + arr[j];
            int bidx = j;
            while( 1 ) {
                int idx = lower_bound(arr.begin(), arr.end(), val) - arr.begin();
                if(arr[idx] != val) {
                    break;
                }
                chk[bidx][idx] = true;
                bidx = idx;
                val += dif;
                cnt++;
            }

            ans = max(ans, cnt);
        }
    }

    printf("%d\n", ans);
    return 0;
}
