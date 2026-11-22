#include <bits/stdc++.h>
using namespace std;

void read(int a);
int calc(int a, bool b);

vector<int> sns[1000010];
vector<int> edge[1000010];

bool chk[1000010];
int DP[1000010][2];
int n;

int main(void)
{
    int i, ans;
    scanf("%d", &n);
    for(i=1;i<=n-1;i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }
    read(1);
    ans = min(calc(1, false), calc(1, true));
    printf("%d\n", ans);
    return 0;
}

void read(int a)
{
    int i;
    chk[a] = true;
    for(i=0;i<edge[a].size();i++) {
        int tmp = edge[a][i];
        if(!chk[tmp]) {
            sns[a].push_back(tmp);
            read(tmp);
        }
    }

    return ;
}

int calc(int a, bool b)
{
    int i;
    if(DP[a][b] != 0) {
        return DP[a][b];
    }
    if(sns[a].size() == 0) {
        return DP[a][b] = b;
    }
    if(b) {
        int res = 0;
        for(i=0;i<sns[a].size();i++) {
            int tmp = sns[a][i];
            res += min(calc(tmp, true), calc(tmp, false));
        }
        return DP[a][b] = res + 1;
    }
    else {
        int res = 0;
        for(i=0;i<sns[a].size();i++) {
            int tmp = sns[a][i];
            res += calc(tmp, true);
        }
        return DP[a][b] = res;
    }
}