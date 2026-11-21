#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<pii> arr;
vector<int> tree;

int init(int st, int fi, int node);
int query(int st, int fi, int l, int r, int node);
void update(int st, int fi, int idx, int node, int value);

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d", &a);
        arr.push_back(pii(a, i));
    }
    sort(arr.begin(), arr.end());

    int height = (int)ceil(log2(n));
    int tree_size = (1 << (height+1));
    tree.resize(tree_size);
    init(0, n-1, 1);

    long long ans = 0;
    for(int i=0;i<n;i++) {
        ans += query(0, n-1, 0, arr[i].second, 1) - 1;
        update(0, n-1, arr[i].second, 1, 0);
    }

    printf("%lld\n", ans);
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

int query(int st, int fi, int l, int r, int node)
{
    if(r < st || fi < l) {
        return 0;
    }
    if(l <= fi && r >= fi) {
        return tree[node];
    }

    int mid = (st + fi) / 2;
    return query(st, mid, l, r, node*2) + query(mid+1, fi, l, r, node*2+1);
}

void update(int st, int fi, int idx, int node, int value)
{
    if(idx < st || fi < idx) {
        return ;
    }
    if(st == fi) {
        if(st == idx) {
            tree[node] = value;
        }
        return ;
    }

    int mid = (st + fi) / 2;
    update(st, mid, idx, node*2, value);
    update(mid+1, fi, idx, node*2+1, value);
    tree[node] = tree[node*2] + tree[node*2+1];
    return ;
}
