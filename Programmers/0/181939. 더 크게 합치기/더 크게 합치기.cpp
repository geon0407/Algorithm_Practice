#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b) {
    int answer = 0; 
    string n1 = to_string(a) + to_string(b), n2 = to_string(b) + to_string(a);
    
    if(n1 > n2) {
        answer = stoi(n1);
    }
    else {
        answer = stoi(n2);
    }
    
    return answer;
}