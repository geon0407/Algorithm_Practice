#include <bits/stdc++.h>
using namespace std;

int facto(int n);

int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", facto(n) / facto(k) / facto(n - k));
    return 0;
}

int facto(int n)
{
    int i, ans=1;
    for(i=2;i<=n;i++) {
        ans *= i;
    }
    return ans;
}
