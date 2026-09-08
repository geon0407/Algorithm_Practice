#include <bits/stdc++.h> 
using namespace std;

int bfs();

int seat[110][110];
int dist[110][110];
int dxdy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;

int main(void)
{
    int i, j;
    scanf("%d%d", &n, &m);
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            scanf("%1d", &seat[i][j]);
        }
    }

    printf("%d\n", bfs());
    return 0;
}

int bfs()
{
    queue<pair<int, int>> q;
    int i, j, k;
    i = j = 1;

    q.push(pair<int, int>(i, j));
    dist[i][j] = 1;

    while(q.size()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();

        for(k=0;k<4;k++) {
            int ni = i + dxdy[k][0];
            int nj = j + dxdy[k][1];

            if(seat[ni][nj] != 0 && dist[ni][nj] == 0) {
                //printf("PUSH : %d %d\n", ni, nj);
                q.push(pair<int, int>(ni, nj));
                dist[ni][nj] = dist[i][j] + 1;
            }
        }
    }

    return dist[n][m];
}
