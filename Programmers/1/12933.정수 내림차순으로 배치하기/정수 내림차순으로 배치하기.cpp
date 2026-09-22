#include <bits/stdc++.h>
using namespace std;

long long solution(long long n) {
    vector<int> arr(10, 0);
    long long answer = 0;
    
    while(n) {
        arr[n%10]++;
        n /= 10;
    }
    
    for(int i=9;i>=0;i--) {
        for(int j=0;j<arr[i];j++) {
            answer *= 10;
            answer += i;
        }
    }
    
    return answer;
}