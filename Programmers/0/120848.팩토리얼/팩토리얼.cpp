#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0, fac=1;
    
    while(fac <= n) {
        fac *= ++answer;
    }
    
    return answer-1;
}