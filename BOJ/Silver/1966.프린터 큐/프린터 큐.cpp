#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main(void)
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n, m;
        scanf("%d%d", &n, &m);

        queue<pii> q;
        priority_queue<int> pq;

        for(int i=0;i<n;i++) {
            int in;
            scanf("%d", &in);
            q.push(pii(i, in));
            pq.push(in);
        }

        int res = 0;
        while(!q.empty()) {
            pii p = q.front();
            q.pop();

            if(p.second == pq.top()) {
                pq.pop();
                res++;

                if(p.first == m) {
                    printf("%d\n", res);
                    break;
                }
            }
            else {
                q.push(p);
            }
        }
    }

    return 0;
}

