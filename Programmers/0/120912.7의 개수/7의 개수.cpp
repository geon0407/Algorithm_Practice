#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    for(auto i : array) {
        while( i ) {
            if(i % 10 == 7) {
                answer++; 
            }
            i /= 10;
        }
    }
    
    return answer;
}