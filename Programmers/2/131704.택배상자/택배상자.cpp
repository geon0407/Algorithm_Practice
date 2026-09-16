#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order) {
    stack<int> sub;
    int answer = 0;

    for(int i=1;i<=order.size();i++) {
        sub.push(i);

        while(!sub.empty() && order[answer] == sub.top()) {
            answer++;
            sub.pop();
        }
    }

    return answer;
}