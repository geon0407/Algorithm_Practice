#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
    
    for(auto c : str) {
        if('a' <= c && c <= 'z') {
            char tmp = 'A' + (c - 'a');
            cout << tmp;
        }
        else {
            char tmp = 'a' + (c - 'A');
            cout << tmp;
        }
    }
    
    return 0;
}