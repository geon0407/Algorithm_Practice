#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, x1, x2, y1, y2, ans=0;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n);

        while(n--) {
            int cx, cy, r;
            double dis1, dis2;
            scanf("%d%d%d", &cx, &cy, &r);

            dis1 = sqrt(pow(x1-cx, 2) + pow(y1-cy, 2));
            dis2 = sqrt(pow(x2-cx, 2) + pow(y2-cy, 2));

            if(dis1 <= r && dis2 <= r) {
                continue;
            }
            else if(dis1 <= r) {
                ans++;
            }
            else if(dis2 <= r) {
                ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}