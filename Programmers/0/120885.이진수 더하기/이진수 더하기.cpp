#include <bits/stdc++.h>
using namespace std;

int binto10(string n) {
    int tot = 0, cur = 1;
    reverse(n.begin(), n.end());
    
    for(int i=0;i<n.size();i++) {
        tot += (n[i] == '1') ? cur : 0;
        cur *= 2;
    }
    
    return tot;
}

string solution(string bin1, string bin2) {
    string answer = "";
    int sum = binto10(bin1) + binto10(bin2);
    
    if(sum == 0) {
        return "0";
    }
    
    while( sum ) {
        answer += to_string(sum % 2);
        sum /= 2;
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}