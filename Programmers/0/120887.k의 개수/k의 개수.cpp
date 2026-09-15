#include <bits/stdc++.h>
using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    for(i;i<=j;i++) {
        int tmp = i;
        while( tmp ) {
            if(tmp%10 == k) {
                answer++;
            }
            tmp /= 10;
        }
    }
    
    return answer;
}