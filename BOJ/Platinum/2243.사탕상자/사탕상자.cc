#include <bits/stdc++.h>
using namespace std;

int query(int st, int fi, int node, int candy);
void update(int st, int fi, int idx, int node, int d);

vector<int> tree;

const int MAX = 1000000;

int main(void)
{
    int n;
    scanf("%d", &n);

    int height = (int)ceil(log2(MAX));
    int tree_sz = (1 << (height + 1));
    tree.resize(tree_sz);

    while(n--) {
        int a, b, c;
        scanf("%d", &a);
        
        if(a == 1) {
            scanf("%d", &b);
            c = query(1, MAX, 1, b);
            update(1, MAX, c, 1, -1);
            printf("%d\n", c);
        }
        else {
            scanf("%d%d", &b, &c);
            update(1, MAX, b, 1, c);
        }
    }

    return 0;
}

int query(int st, int fi, int node, int candy)
{
    if(st == fi) {
        return st;
    }

    int mid = (st + fi) / 2;

    if(tree[node*2] >= candy) {
        return query(st, mid, node*2, candy);
    }
    return query(mid+1, fi, node*2+1, candy - tree[node*2]);
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
