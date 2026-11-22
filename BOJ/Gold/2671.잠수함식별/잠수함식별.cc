#include <bits/stdc++.h>
using namespace std;

int p[11][2]={{7,1},{2,9},{3,9},{3,4},{7,5},{6,5},{3,8},{9,8},{7,1},{9,9}}, n;
string s;

int main(void)
{
    int i;
    cin >> s;
    for(i=0;i<s.length();i++) {
        n=p[n][s[i]-'0'];
    }
    if(n==4 || n==5 || n==8) {
        printf("SUBMARINE\n");
    }
    else {
        printf("NOISE\n");
    }
    return 0;
}