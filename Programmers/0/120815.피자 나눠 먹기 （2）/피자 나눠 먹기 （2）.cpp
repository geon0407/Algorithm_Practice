#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    while(++answer) {
        if(answer*6 % n == 0) {
            break;
        }
    }
    
    return answer;
}