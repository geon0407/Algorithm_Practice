#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int INF = 1000000000;

int n, m;
vector<vector<pii>> adj;
vector<int> parent;

int dijkstra(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj.resize(n+1);
    parent.resize(n+1, -1);

    for(int i=0;i<m;i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int dist = dijkstra(0, 0);
    if(dist == -1) {
        cout << -1;
        return 0;
    }

    int answer = 0;
    for(int p=n;p!=parent[p];p=parent[p]) {
        int tmp = dijkstra(p, parent[p]);

        if(tmp == -1) {
            answer = -1;
            break;
        }

        answer = max(answer, tmp-dist);
    }

    cout << answer;

    return 0;
}

int dijkstra(int a, int b)
{
    vector<int> dist(n+1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[1] = 0;
    if(a == 0) {
        parent[1] = 1;
    }
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if(cost > dist[cur]) {
            continue;
        }

        for(auto [next, weight] : adj[cur]) {
            if((cur == a && next == b) ||
               (cur == b && next == a)) {
                continue;
            }

            int nextCost = cost + weight;
            if(nextCost < dist[next]) {
                dist[next] = nextCost;

                if(a == 0) {
                    parent[next] = cur;
                }

                pq.push({nextCost, next});
            }
        }
    }

    return (dist[n] == INF) ? -1 : dist[n];
}