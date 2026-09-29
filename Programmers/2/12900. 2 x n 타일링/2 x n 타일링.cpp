#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int memo[60010];

int solution(int n) {
    memo[1] = 1;
    memo[2] = 2;
    for(int i=3;i<=n;i++) {
        memo[i] = (memo[i-1] + memo[i-2]) % mod;
    }
    
    return memo[n];
}