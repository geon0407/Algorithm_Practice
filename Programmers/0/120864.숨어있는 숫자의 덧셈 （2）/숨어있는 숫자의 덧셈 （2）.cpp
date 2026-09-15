#include <bits/stdc++.h>
using namespace std;

int solution(string my_string) {
    int answer = 0;
    string tmp;
    
    my_string += 'a';
    for(auto c : my_string) {
        if('0' <= c && c <= '9') {
            tmp += c;
        }
        else {
            if(!tmp.empty()) {
                answer += stoi(tmp);
                tmp.clear();
            }
        }
    }
    
    return answer;
}