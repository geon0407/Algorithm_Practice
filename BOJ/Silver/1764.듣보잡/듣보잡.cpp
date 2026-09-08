#include <bits/stdc++.h>
using namespace std;

map<string, int> l;
vector<string> ans;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i=0;i<n+m;i++) {
        string str;
        cin >> str;

        l[str]++;
        if(l[str] > 1) {
            ans.push_back(str);
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i << endl;
    }
    return 0;
}
