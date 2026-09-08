#include <bits/stdc++.h> 
using namespace std;

int find_root(int x);
void union_tree(int x, int y);

int root[1010];
bool chk[1010];

int main(void)
{
    int i, n, m, ans=0;
    scanf("%d%d", &n, &m);
    for(i=1;i<=n;i++) {
        root[i] = i;
    }

    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        union_tree(a, b);
    }

    for(i=1;i<=n;i++) {
        int tmp = find_root(i);
        if(chk[tmp] == false) {
            chk[tmp] = true;
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}

int find_root(int x)
{
    if(root[x] == x) {
        return x;
    }
    else {
        return root[x] = find_root(root[x]);
    }
}

void union_tree(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    root[y] = x;

    return ;
}
