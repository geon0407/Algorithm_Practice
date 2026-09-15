#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers, int k) {
    int cur = -1; 
    
    while(k--) {
        cur += 2;
        if(cur > numbers.size()) {
            cur -= numbers.size();
        }
    }
    
    return numbers[cur-1];
}