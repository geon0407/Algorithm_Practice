#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> cnt;
    
    for(auto &s : completion) {
        cnt[s]++;
    }    
    
    for(auto &s : participant) {
        if(cnt[s] == 0) {
            return s;
        }
        
        cnt[s]--;
    }
}