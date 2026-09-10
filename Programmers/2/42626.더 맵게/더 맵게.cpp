#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;
    
    for(auto i : scoville) {
        pq.push(i);
    }
    
    if(!pq.size() || pq.top() >= K) {
        return 0;
    }
    
    while( 1 ) {
        int t1 = pq.top();
        pq.pop();
        if(!pq.size() && t1 < K) {
            return -1;
        } 
        int t2 = pq.top();
        pq.pop();
        
        answer++;
        pq.push(2*t2 + t1);
        if(pq.top() >= K) {
            return answer;
        }
    }
}