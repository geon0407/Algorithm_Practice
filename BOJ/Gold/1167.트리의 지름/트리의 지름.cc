#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> tree;
vector<int> dist;
vector<bool> vis;

void f(int now);

int main(void)
{
    int v;
    scanf("%d", &v);
    tree.resize(v);
    dist = vector<int> (v, 0);
    vis = vector<bool> (v, false);
    
    int node, to, l;
    for(int i=0;i<v;i++) {
        scanf("%d", &node);
        node -= 1;
        
        to = 0;
        while(to != -1) {
            scanf("%d", &to);
            
            if(to == -1) {
                continue;
            }
            
            scanf("%d", &l);
            tree[node].push_back(make_pair(to-1, l));
        }
    }
    
    int ans = 0;
    f(0);
    
    for(int i=0;i<v;i++) {
        if(dist[ans] < dist[i]) {
            ans = i;
        }
    }
    
    for(int i=0;i<v;i++) {
        dist[i] = 0;
        vis[i] = false;
    }
    
    f(ans);
    ans = 0;
    for(int i=0;i<v;i++) {
        ans = max(ans, dist[i]);
    }
    
    printf("%d\n", ans);
    return 0;
}

void f(int now)
{
    queue<int> q;
    q.push(now);
    vis[now] = true;
    
    while(!q.empty()) {
        now = q.front();
        q.pop();
        
        for(auto i : tree[now]) {
            if(!vis[i.first]) {
                q.push(i.first);
                vis[i.first] = true;
                dist[i.first] = i.second + dist[now];
            }
        }
    }
    
    return ;
}