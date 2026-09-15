#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> v;
    vector<int> answer;
    
    for(auto i : emergency) {
        v.push_back(i);
    }
    sort(emergency.begin(), emergency.end(), greater<int>());
    
    for(auto p : v) {
        for(int i=0;i<emergency.size();i++) {
            if(p == emergency[i]) {
                answer.push_back(i+1);    
            }
        }
    }
    
    return answer;
}