#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int i, j, n;
    string str;
    scanf("%d", &n);
    cin >> str;

    string res = str;

    for(i=1;i<n;i++) {
        string tmp;
        cin >> tmp;

        for(j=0;j<str.size();j++) {
            if(str[j] != tmp[j]) {
                res[j] = '?';
            }
        }
    }

    cout << res << endl;
    return 0;
}