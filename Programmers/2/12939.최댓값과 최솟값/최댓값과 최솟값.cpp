#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    int M, m, n;

    M = numeric_limits<int>::min();
    m = numeric_limits<int>::max();
    
    istringstream iss(s);
    while(iss >> n) {
        M = max(M, n);
        m = min(m, n);
    }
    
    answer += to_string(m) + " " + to_string(M);
    
    return answer;
}