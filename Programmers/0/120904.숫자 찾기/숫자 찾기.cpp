#include <bits/stdc++.h>
using namespace std;

int solution(int num, int k) {
    string tmp = to_string(num);
    int answer = -1;
    
    for(int i=0;i<tmp.size();i++) {
        if(tmp[i]-'0' == k) {
            return i+1;
        }
    }
    
    return answer;
}