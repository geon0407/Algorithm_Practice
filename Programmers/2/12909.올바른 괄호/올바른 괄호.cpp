#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    int op = 0;
    
    for(auto &c : s) {
        if(c == '(') {
            op++;
        }
        else {
            if(!op) {
                return false;
            }
            op--;
        }
    }    
    
    return op ? false : true;
}