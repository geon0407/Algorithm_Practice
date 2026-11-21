#include <bits/stdc++.h>
using namespace std;

bool f(int want);

vector<int> memo[210];
int room[210];
bool chk[210];

int main(void)
{
    int n, m, i, ans=0;
    scanf("%d%d", &n, &m);
    for(i=1;i<=n;i++) {
        int a, b;
        scanf("%d", &a);
        while(a--) {
            scanf("%d", &b);
            memo[i].push_back(b);
        }
    }

    for(i=1;i<=n;i++) {
        fill(chk, chk+n, false);
        if(f(i)) {
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}

bool f(int want)
{
    if(chk[want]) {
        return false;
    }

    chk[want] = true;
    for(auto idx : memo[want]) {
        if(!room[idx] ||f(room[idx])) {
            room[idx] = want;
            return true;
        }
    }

    return false;
}
