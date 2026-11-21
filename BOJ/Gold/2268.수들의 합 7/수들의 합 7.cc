#include <bits/stdc++.h>
using namespace std;

long long init(vector<long long> &arr, vector<long long> &tree, int node, int st, int fi);
long long sum(vector<long long> &tree, int node, int st, int fi, int left, int right);
void update(vector<long long> &tree, int node, int st, int fi, int idx, long long dif);

int n, m;

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<long long> arr(n);
    vector<long long> tree(4*n);

    while(m--) {
        int com;
        scanf("%d", &com);
        if(com == 0) {
            int i, j;
            scanf("%d%d", &i, &j);
            printf("%lld\n", sum(tree, 1, 0, n-1, min(i, j) - 1, max(i, j) - 1));
        }
        else {
            int i, k, dif;
            scanf("%d%d", &i, &k);

            dif = k - arr[i-1];
            arr[i-1] = k;
            update(tree, 1, 0, n-1, i-1, dif);
        }
    }
}

long long init(vector<long long> &arr, vector<long long> &tree, int node, int st, int fi)
{
    if(st == fi) {
        return tree[node] = arr[st];
    }

    int mid = (st + fi) / 2;

    return tree[node] = init(arr, tree, node*2, st, mid) + init(arr, tree, node*2+1, mid+1, fi);
}

long long sum(vector<long long> &tree, int node, int st, int fi, int left, int right)
{
    if(left > fi || right < st) {
        return 0;
    }

    if(left <= st && fi <= right) {
        return tree[node];
    }

    int mid = (st + fi) / 2;

    return sum(tree, node*2, st, mid, left, right) + sum(tree, node*2+1, mid+1, fi, left, right);
}

void update(vector<long long> &tree, int node, int st, int fi, int idx, long long dif)
{
    if(!(st <= idx && idx <= fi)) {
        return ;
    }

    tree[node] += dif;

    if(st != fi) {
        int mid = (st + fi) / 2;
        update(tree, node*2, st, mid, idx, dif);
        update(tree, node*2+1, mid+1, fi, idx, dif);
    }

    return ;
}