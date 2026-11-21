#include <bits/stdc++.h>
using namespace std;

void init(int N);
int find_root(int r);
void union_set(int s1, int s2);

int root[210];

int main(void)
{
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    init(n);

    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            int in;
            scanf("%d", &in);
            if(in == 1) {
                if(find_root(i) != find_root(j)) {
                    union_set(i, j);
                }
            }
        }
    }

    int k;
    scanf("%d", &k);
    k = find_root(k);
    for(i=1;i<m;i++) {
        int x;
        scanf("%d", &x);
        if(k != find_root(x)) {
            printf("NO\n");
            exit(0);
        }
    }

    printf("YES\n");
    return 0;
}

void init(int N)
{
    int i;
    for(i=0;i<=N;i++) {
        root[i] = i;
    }

    return ;
}

int find_root(int r)
{
    if(r == root[r]) {
        return r;
    }

    return root[r] = find_root(root[r]);
}

void union_set(int s1, int s2)
{
    s1 = find_root(s1);
    s2 = find_root(s2);

    if(s1 == s2) {
        return ;
    }

    if(s1 > s2) {
        swap(s1, s2);
    }

    root[s2] = s1;
    return ;
}