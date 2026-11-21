#include <bits/stdc++.h>

using namespace std;

string s;
int arr[30] = { 0 };

int main(void)
{
    char ans;
    int i, j, m=0;

    getline(cin, s);

    for(i=0;i<s.length();i++) {
        if(s[i] >= 65 && s[i] <= 90) {
            arr[s[i] - 65]++;
        }
        else if(s[i] >= 97 && s[i] <= 122) {
            arr[s[i] - 97]++;
        }
    }

    for(i=0;i<26;i++) {
        if(arr[i] > m) {
            ans = i + 65;
            m = arr[i];
        }
        else if(arr[i] == m) {
            ans = '?';
        }
    }

    printf("%c\n", ans);
    return 0;
}
