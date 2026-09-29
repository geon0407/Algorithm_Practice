#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1;i<=n;i++) {
        if(n % 2) {
            answer += ((i % 2) ? i : 0);
        }
        else {
            answer += ((i % 2) ? 0 : i*i);
        }
    }
    
    return answer;
}