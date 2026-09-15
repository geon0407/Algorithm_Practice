#include <bits/stdc++.h>
using namespace std;

string solution(string my_string) {
    string answer = ""; 
    
    for(auto c : my_string) {
        if('A' <= c && c <= 'Z') {
            answer += c - 'A' + 'a';
        }
        else {
            answer += c;
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}