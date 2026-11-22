#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    
    for(auto c : s) {
        if('a' <= c && c <= 'z') {
            c = c - 'a' + 'A';
        }
        else {
            c = c - 'A' + 'a';
        }
        
        cout << c;
    }
    
    return 0;
}