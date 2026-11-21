#include <bits/stdc++.h>
using namespace std;

void f();

vector<int> graph[32010];
int deep[32010];
int n, m;

int main(void)
{
    int i;
    scanf("%d%d", &n, &m);
    for(i=0;i<m;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        deep[b]++;
    }

    f();
    return 0;
}

void f()
{
    int i;
    queue<int> q;

    for(i=1;i<=n;i++) {
        if(deep[i] == 0) {
            q.push(i);
        }
    }

    while(q.size()) {
        int tmp = q.front();
        printf("%d ", tmp);
        q.pop();

        for(i=0;i<graph[tmp].size();i++) {
            deep[graph[tmp][i]]--;
            if(deep[graph[tmp][i]] == 0) {
                q.push(graph[tmp][i]);
            }
        }
    }

    return ;
}