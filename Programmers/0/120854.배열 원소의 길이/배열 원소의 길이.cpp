#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    
    for(auto i : strlist) {
        answer.push_back(i.size());
    }
    
    return answer;
}