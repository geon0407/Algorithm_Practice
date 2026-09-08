#include <bits/stdc++.h>
using namespace std;

int init(int st, int fi, int node);
int query(int st, int fi, int node, int candy);
void update(int st, int fi, int idx, int node, int d);

vector<int> tree;

int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);

    int height = (int)ceil(log2(n));
    int tree_sz = (1 << (height+1));
    tree.resize(tree_sz);
    init(1, n, 1);

    printf("<");
    int q = k-1;
    while(1) {
        int res = query(1, n, 1, q+1);
        printf("%d", res);
        update(1, n, res, 1, -1);

        if(tree[1] == 0) {
            break;
        }

        q += k-1;
        q %= tree[1];
        printf(", ");
    }
    printf(">\n");

    return 0;
}

int init(int st, int fi, int node)
{
    if(st == fi) {
        return tree[node] = 1;
    }

    int mid = (st + fi) / 2;
    return tree[node] = init(st, mid, node*2) + init(mid+1, fi, node*2+1);
}

int query(int st, int fi, int node, int cnt)
{
    if(st == fi) {
        return st;
    }

    int mid = (st + fi) / 2;

    if(tree[node*2] >= cnt) {
        return query(st, mid, node*2, cnt);
    }
    return query(mid+1, fi, node*2+1, cnt - tree[node*2]);
}

void update(int st, int fi, int idx, int node, int d)
{
    if(idx < st || fi < idx) {
        return ;
    }

    if(st == fi) {
        if(st == idx) {
            tree[node] += d;
        }

        return ;
    }

    int mid = (st + fi) / 2;

    update(st, mid, idx, node*2, d);
    update(mid+1, fi, idx, node*2+1, d);
    tree[node] = tree[node*2] + tree[node*2+1];

    return ;
}
