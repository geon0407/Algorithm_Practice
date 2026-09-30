#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int s1 = 0, s2 = 1;
    
    for(auto &i : num_list) {
        s1 += i;
        s2 *= i;
    }
    
    return (s2 < s1*s1) ? 1 : 0;
}