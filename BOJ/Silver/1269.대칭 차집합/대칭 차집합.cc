#include <bits/stdc++.h>
using namespace std;

map<int, int> s;
vector<int> v;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, ans=0;
    cin >> a >> b;
    for(int i=0;i<a+b;i++) {
        int in;
        cin >> in;
        v.push_back(in);
        s[in]++;
    }

    for(int i=0;i<a+b;i++) {
        if(s[v[i]] == 1) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}
