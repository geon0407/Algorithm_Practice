#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--) {
        int a;
        string str;
        cin >> a >> str;
        str.erase(a-1, 1);
        cout << str << endl;
    }

    return 0;
}