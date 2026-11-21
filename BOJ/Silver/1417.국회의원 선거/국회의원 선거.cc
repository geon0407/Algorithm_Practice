#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>> q;

int main(void)
{
    int n, das, ans;
    scanf("%d%d", &n, &das);

    if(n == 1) {
        printf("0\n");
        return 0;
    }

    for(int i=2;i<=n;i++) {
        scanf("%d", &ans);
        q.push(make_pair(ans, i));
    }

    ans = 0;
    while(das+ans++ <= q.top().first) {
        pair<int, int> tmp = q.top();
        q.pop();
        tmp.first--;
        q.push(tmp);
    }

    printf("%d\n", ans-1);
    return 0;
}
