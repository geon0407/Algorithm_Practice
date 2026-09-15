#include <bits/stdc++.h>
using namespace std;

int solution(int angle) {
    int ans = 0;
    
    if(angle < 90) {
        ans = 1;
    }
    else if(angle == 90) {
        ans = 2;
    }
    else if(angle < 180) {
        ans = 3;
    }
    else {
        ans = 4;
    }
    
    return ans;
}