#include <bits/stdc++.h>
using namespace std;

string solution(string rsp) {
    string answer = "";
    
    for(auto c : rsp) {
        int k = c - '0';
        
        if(k == 0) {
            answer += "5";
        }
        else if(k == 2) {
            answer += "0";
        }
        else {
            answer += "2";
        }
    }
    
    return answer;
}