#include <bits/stdc++.h>
using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string tmp; 
    
    for(auto c : my_str) {
        tmp += c;
        if(tmp.size() == n) {
            answer.push_back(tmp);
            tmp.clear();
        }
    }
    
    if(!tmp.empty()) {
        answer.push_back(tmp);
    }
    return answer;
}