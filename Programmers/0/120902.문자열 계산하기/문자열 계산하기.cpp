#include <bits/stdc++.h>
using namespace std;

int solution(string my_string) {
    string num;
    char cmd = '\0';
    int a;
    
    my_string.erase(remove(my_string.begin(), my_string.end(), ' '), my_string.end());
    for(auto c : my_string) {
        if(c == '+' || c == '-') {
            if(cmd == '\0') {
                cmd = c;
                a = stoi(num);
                num.clear();
            }
            else if(cmd == '+') {
                cmd = c;
                a += stoi(num);
                num.clear();
            }
            else {
                cmd = c;
                a -= stoi(num);
                num.clear();
            }
        }
        else {
            num += c;
        }
    }
    
    if(cmd == '+') {
        a += stoi(num);
    }
    else {
        a -= stoi(num);
    }
    
    return a;
}