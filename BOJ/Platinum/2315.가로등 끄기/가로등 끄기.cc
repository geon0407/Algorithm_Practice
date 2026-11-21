#include <bits/stdc++.h>
using namespace std;

int dp(int left, int right, bool dir);

int d[1010], w[1010], sum[1010], memo[1010][1010][2];
int n, m;

int main(void)
{
    int i;
    scanf("%d%d", &n, &m);
    for(i=0;i<n;i++) {
        scanf("%d%d", &d[i], &w[i]);
        sum[i+1] = sum[i] + w[i];
    }
    memset(memo, -1, sizeof(memo));
    printf("%d\n", dp(m-1, n-m, 0));
    return 0;
}

int dp(int left, int right, bool dir)
{
    int &tmp = memo[left][right][dir];
    if(tmp != -1) {
        return tmp;
    }
    if(left == 0 && right == 0) {
        return tmp = 0;
    }

    tmp = numeric_limits<int>::max();
    if(left) {
        tmp = dp(left-1, right, false) + (sum[left]+sum[n]-sum[n-right]) * (dir?d[n-right-1]-d[left-1]:d[left]-d[left-1]);
    }
    if(right) {
        tmp = min(tmp, dp(left, right-1, true) + (sum[left]+sum[n]-sum[n-right]) * (dir?d[n-right]-d[n-right-1]:d[n-right]-d[left]));
    }

    return tmp;
}