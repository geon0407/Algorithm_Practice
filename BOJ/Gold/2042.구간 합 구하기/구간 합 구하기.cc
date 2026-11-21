#include <bits/stdc++.h>
using namespace std;

void upd(vector<long long int> &tree, int i, long long int val);
long long int sum(vector<long long int> &tree, int i);

int n, m, k;

int main(void)
{
    int i;
    scanf("%d%d%d", &n, &m, &k);

    vector<long long int> arr(n+1);
    vector<long long int> tree(n+1);

    for(i=1;i<=n;i++) {
        scanf("%lld", &arr[i]);
        upd(tree, i, arr[i]);
    }

    m += k;
    while(m--) {
        int com;
        scanf("%d", &com);
        if(com == 1) {
            int idx;
            long long int val;
            scanf("%d %lld", &idx, &val);

            long long int dif = val - arr[idx];
            arr[idx] = val;

            upd(tree, idx, dif);
        }
        else {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%lld\n", sum(tree, b) - sum(tree, a - 1));
        }
    }

    return 0;
}

void upd(vector<long long int> &tree, int i, long long int val)
{
    while(i < tree.size()) {
        tree[i] += val;
        i += (i & -i);
    }

    return ;
}

long long int sum(vector<long long int> &tree, int i)
{
    long long int res = 0;
    while(i > 0) {
        res += tree[i];
        i -= (i & -i);
    }

    return res;
}