#include <bits/stdc++.h> 
using namespace std;

void dfs(int idx);
void bfs(int idx);

queue<int> q;

bool vis[1010];
int n, m, v;
int memo[1010][1010];

int main(void)
{
    int i;
    scanf("%d%d%d", &n, &m, &v);

    for(i=0;i<m;i++) {
        int from, to;
        scanf("%d%d", &from, &to);
        memo[to][from] = memo[from][to] = 1;
    }

    vis[v] = true;
    dfs(v);
    printf("\n");

    memset(vis, false, sizeof(vis));
    bfs(v);
    printf("\n");

    return 0;
}

void dfs(int idx)
{
    int i;

    printf("%d ", idx);

    for(i=1;i<=n;i++) {
        if(memo[idx][i] && !vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }

    return ;
}

void bfs(int idx)
{
    int i;

    q.push(idx);
    vis[idx] = 1;

    while(!q.empty()) {
        idx = q.front();
        q.pop();
        printf("%d ", idx);
        for(i=1;i<=n;i++) {
            if(memo[idx][i] && !vis[i]) {
                vis[i] = true;
                q.push(i);
            }
        }
    }

    return ;
}
