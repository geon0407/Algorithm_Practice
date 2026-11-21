#include <bits/stdc++.h>
using namespace std;

void init(int node, int st, int fi);
pair<int, int> ans(int node, int st, int fi, int l, int r);

vector<int> arr, min_tree, max_tree;
int n, m;

int main(void)
{
    int i;
    scanf("%d%d", &n, &m);
    min_tree.resize(4*n);
    max_tree.resize(4*n);

    for(i=0;i<n;i++) {
        int in;
        scanf("%d", &in);
        arr.push_back(in);
    }

    init(1, 0, n-1);
    for(i=0;i<m;i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        pair<int, int> res = ans(1, a-1, b-1, 0, n-1);
        printf("%d %d\n", res.first, res.second);
    }

    return 0;
}

void init(int node, int st, int fi)
{
    if(st == fi) {
        min_tree[node] = max_tree[node] = arr[fi];
        return ;
    }

    int mid = (st + fi) / 2;
    init(node*2, st, mid);
    init(node*2+1, mid+1, fi);
    min_tree[node] = min(min_tree[node*2], min_tree[node*2+1]);
    max_tree[node] = max(max_tree[node*2], max_tree[node*2+1]);

    return ;
}

pair<int, int> ans(int node, int st, int fi, int l, int r)
{
    if(l > fi || r < st) {
        return pair<int, int>(numeric_limits<int>::max(), 0);
    }

    if(st <= l && r <= fi) {
        return pair<int, int>(min_tree[node], max_tree[node]);
    }

    pair<int, int> left, right;
    int mid = (l + r) / 2;
    left = ans(node*2, st, fi, l, mid);
    right = ans(node*2+1, st, fi, mid+1, r);
    return pair<int, int>(min(left.first, right.first), max(left.second, right.second));
}