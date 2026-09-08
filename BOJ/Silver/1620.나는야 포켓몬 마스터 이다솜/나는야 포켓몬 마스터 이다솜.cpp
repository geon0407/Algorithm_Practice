#include <bits/stdc++.h>
using namespace std;

map<string, int> name;
string num[100010];

int n, m;

int main(void)
{
    int i;
    scanf("%d%d", &n, &m);
    for(i=0;i<n;i++) {
        string s;
        cin >> s;
        name.insert(pair<string, int>(s, i+1));
        num[i] = s;
    }

    for(i=0;i<m;i++) {
        char str[25];
        scanf("%s", str);

        if(isdigit(str[0])) {
            cout << num[atoi(str)-1] << "\n";
        }
        else {
            string tmp = str;
            printf("%d\n", name[tmp]);
        }
    }

    return 0;
}
