#include <bits/stdc++.h>
using namespace std;

int solution(int x, int y, int n) {
    vector<int> dist(y+1, -1);
    queue<int> q;

    q.push(x);
    dist[x] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if(now == y) {
            return dist[now];
        }

        for(auto next : {now*3, now*2, now+n}) {
            if(next > y || dist[next] != -1) {
                continue;
            }

            q.push(next);
            dist[next] = dist[now] + 1;
        }
    }

    return -1;
}