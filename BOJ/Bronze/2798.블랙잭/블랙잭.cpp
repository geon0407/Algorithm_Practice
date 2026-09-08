#include <bits/stdc++.h>
using namespace std;

int card[110];
int n, m;

int main(void)
{
    int i, j, k, ans=0;
    scanf("%d%d", &n, &m);
    for(i=0;i<n;i++) {
        scanf("%d", &card[i]);
    }

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            for(k=0;k<n;k++) {
                if(i == j || j == k || k == i) {
                    continue;
                }

                int sum = card[i] + card[j] + card[k];
                if(sum > m) {
                    continue;
                }
                ans = max(ans, sum);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
