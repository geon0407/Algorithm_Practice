#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    
    for(int i : array) {
        if(i == n) {
            answer++;
        }
    }
    
    return answer;
}