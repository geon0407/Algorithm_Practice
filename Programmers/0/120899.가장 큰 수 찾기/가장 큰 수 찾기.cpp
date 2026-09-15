#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    
    answer.push_back(array[0]);
    answer.push_back(0);
    
    for(int i=0;i<array.size();i++) {
        if(array[i] > answer[0]) {
            answer[0] = array[i];
            answer[1] = i;
        }
    }
    
    return answer;
}