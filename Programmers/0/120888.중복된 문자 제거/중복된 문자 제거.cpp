#include <bits/stdc++.h>
using namespace std;

string solution(string my_string) {
    string answer = "";
    answer.push_back(my_string[0]);
    
    for(auto c : my_string) {
        bool flag = true;
        
        for(auto k : answer) {
            if(k == c) {
                flag = false;
                break;
            }
        }
        
        if(flag) {
            answer += c;
        }
    }
    
    return answer;
}