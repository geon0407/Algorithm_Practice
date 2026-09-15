#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    
    s += "0";
    sort(s.begin(), s.end());
    s += "0";
    for(int i=1;i<s.size()-1;i++) {
        if(s[i-1] != s[i] && s[i] != s[i+1]) {
            answer += s[i];
        }
    }
    
    return answer;
}