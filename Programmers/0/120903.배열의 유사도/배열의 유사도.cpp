#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    for(auto str : s1) {
        for(auto k : s2) {
            if(str == k) {
                answer++;
            }
        }
    }
    
    return answer;
}