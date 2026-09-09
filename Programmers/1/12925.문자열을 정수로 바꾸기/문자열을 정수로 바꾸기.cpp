#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 0, flag = 1;
    
    for(auto c : s) {
        if(c == '+') {
            flag = 1;
        }
        else if(c == '-') {
            flag = -1;
        }
        else {
            answer *= 10;
            answer += (c - '0');
        }
    }
    
    return flag * answer;
}