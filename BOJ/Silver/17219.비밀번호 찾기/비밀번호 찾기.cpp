#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    map<string, string> pw;
    int n, m;
    cin >> n >> m;

    while(n--) {
        string url, p;
        cin >> url >> p;
        pw.insert({url, p});
    }

    while(m--) {
        string cmd;
        cin >> cmd;
        cout << pw[cmd] << "\n";
    }

    return 0;
}
