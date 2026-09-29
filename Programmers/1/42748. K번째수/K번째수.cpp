#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto &c : commands) {
        vector<int> tmp;
        
        for(int i=c[0];i<=c[1];i++) {
            tmp.push_back(array[i-1]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[c[2]-1]);
    }
    
    return answer;
}