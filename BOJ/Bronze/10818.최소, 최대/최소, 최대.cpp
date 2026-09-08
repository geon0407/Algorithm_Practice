#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int i, n, ans_min=1000001, ans_max=-1000001;
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        int in;
        scanf("%d", &in);
        ans_min = min(ans_min, in);
        ans_max = max(ans_max, in);
    }
    printf("%d %d\n", ans_min, ans_max);
    return 0;
}
