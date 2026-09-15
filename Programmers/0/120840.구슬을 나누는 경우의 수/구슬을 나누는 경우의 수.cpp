#include <bits/stdc++.h>
using namespace std;

int solution(int balls, int share) {
    int memo[40][40];
    
    memo[1][0] = 1;
    memo[1][1] = 1;
    for(int i=2;i<=30;i++) {
        memo[i][0] = 1;
        for(int j=1;j<=30;j++) {
            memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
        }
    }
    
    return memo[balls][share];
}