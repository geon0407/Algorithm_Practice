#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll query(vector<ll> &tree, int i)
{
    ll res = 0;
    while(i > 0) {
        res += tree[i];
        i -= (i & -i);
    }

    return res;
}

void upd(vector<ll> &tree, int i, ll v)
{
    while(i < tree.size()) {
        tree[i] += v;
        i += (i & -i);
    }

    return ;
}

int main(void)
{
    int i, n, q;
    scanf("%d%d", &n, &q);

    vector<ll> tree(n+1);
    vector<ll> arr(n+1);
    for(i=1;i<=n;i++) {
        scanf("%lld", &arr[i]);
        upd(tree, i, arr[i]);
    }

    while(q--) {
        ll x, y, a, b;
        scanf("%lld%lld", &x, &y);
        printf("%lld\n", query(tree, max(x, y)) - query(tree, min(x, y)-1));

        scanf("%lld%lld", &a, &b);
        ll val = b - arr[a];
        arr[a] = b;
        upd(tree, a, val);
    }

    return 0;
}
