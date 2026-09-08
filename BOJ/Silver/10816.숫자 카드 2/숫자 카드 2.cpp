#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(void)
{
    int n, m;
    scanf("%d", &n);
    while(n--) {
        int in;
        scanf("%d", &in);
        v.push_back(in);
    }
    sort(v.begin(), v.end());

    scanf("%d", &m);
    while(m--) {
        int in;
        scanf("%d", &in);
        printf("%d ", upper_bound(v.begin(), v.end(), in) - lower_bound(v.begin(), v.end(), in));
    }

    return 0;
}
