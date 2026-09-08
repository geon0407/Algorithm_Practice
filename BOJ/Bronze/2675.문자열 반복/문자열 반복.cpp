#include <bits/stdc++.h>
using namespace std;

string calc(int t, string s);

int main(void)
{
    int i, n;
    cin >> n;

    for(i=0;i<n;i++) {
        int t;
        string s;
        cin >> t;
        cin >> s;
        cout << calc(t, s) << endl;
    }

    return 0;
}

string calc(int t, string s)
{
    int i, j;
    string ans = "";

    for(i=0;i<s.length();i++) {
        for(j=0;j<t;j++) {
            ans += s[i];
        }
    }

    return ans;
}
