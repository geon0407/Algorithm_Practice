#include <bits/stdc++.h>

using namespace std;

int check(string s);

int main(void)
{
    int i, n, cnt=0;
    cin >> n;

    for(i=0;i<n;i++) {
        string s;
        cin >> s;

        if(check(s)) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}

int check(string s)
{
    int alpha[30] = { 0 };
    int i;

    for(i=0;i<s.length();i++) {
        if(alpha[s[i] - 'a']) {
            return 0;
        }
        else {
            char tmp = s[i];
            alpha[s[i] - 'a'] = 1;

            while( 1 ) {
                if(tmp != s[++i]) {
                    i--;
                    break;
                }
            }
        }
    }

    return 1;
}
