#include <bits/stdc++.h>
using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(auto c : my_string) {
        if('a' <= c && c <= 'z') {
            answer += c - 'a' + 'A';
        }
        else {
            answer += c - 'A' + 'a';
        }
    }
    
    return answer;
}