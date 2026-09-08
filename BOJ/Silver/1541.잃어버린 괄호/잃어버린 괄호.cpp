#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    string s, num = "";
    bool chk = false;
    int ans = 0;
    cin >> s;

    s += '*';
    for(auto c : s) {
        if(c == '+' || c == '-' || c == '*') {
            if(chk) {
                ans -= stoi(num);
            }
            else {
                ans += stoi(num);
            }

            num = "";
        }
        else {
            num += c;
        }

        if(c == '-') {
            chk = true;
        }
    }

    cout << ans;
    return 0;
}
