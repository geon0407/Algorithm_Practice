#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int h=0, z=0;
    
    for(int i : num_list) {
        (i % 2) ? h++ : z++;
    }
    
    answer.push_back(z);
    answer.push_back(h);
    return answer;
}