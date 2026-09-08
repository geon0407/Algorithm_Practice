#include <bits/stdc++.h>
using namespace std;

int bfs();

int dist[100010];
int n, k;

int main(void)
{
    scanf("%d%d", &n, &k);
    printf("%d\n", bfs());
    return 0;
}

int bfs()
{
    queue<int> q;
    dist[n] = 1;

    q.push(n);
    while(q.size()) {
        int tmp = q.front();
        q.pop();

        if(tmp == k) {
            return dist[tmp] - 1;
        }

        if(tmp-1 >= 0 && dist[tmp-1] == 0) {
            q.push(tmp-1);
            dist[tmp-1] = dist[tmp] + 1;
        }
        if(tmp+1 <= 100000 && dist[tmp+1] == 0) {
            q.push(tmp+1);
            dist[tmp+1] = dist[tmp] + 1;
        }
        if(tmp*2 <= 100000 && dist[2*tmp] == 0) {
            q.push(2*tmp);
            dist[2*tmp] = dist[tmp] + 1;
        }
    }
}
