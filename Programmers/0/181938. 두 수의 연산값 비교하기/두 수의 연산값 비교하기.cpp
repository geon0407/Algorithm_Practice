#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b) {
    int answer = max(2*a*b, stoi(to_string(a)+to_string(b)));
    
    return answer;
}