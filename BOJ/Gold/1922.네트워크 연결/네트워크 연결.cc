#include <bits/stdc++.h>
using namespace std;

void union_tree(int a, int b);
int find_root(int x);

pair<int, pair<int, int>> e[100010];
int root[1010];

int main(void)
{
    int n, m, ans=0;
    scanf("%d%d", &n, &m);

    for(int i=0;i<n;i++) {
        root[i] = i;
    }

    for(int i=0;i<m;i++) {
        scanf("%d%d%d", &e[i].second.first, &e[i].second.second, &e[i].first);
    }
    sort(e, e+m);

    for(int i=0;i<m;i++) {
        int a = e[i].second.first, b = e[i].second.second;
        if(find_root(a) != find_root(b)) {
            union_tree(a, b);
            ans += e[i].first;
        }
    }

    printf("%d\n", ans);
    return 0;
}

void union_tree(int a, int b)
{
    a = find_root(a);
    b = find_root(b);

    if(a != b) {
        root[b] = a;
    }

    return ;
}

int find_root(int x)
{
    if(root[x] == x) {
        return x;
    }

    return root[x] = find_root(root[x]);
}
