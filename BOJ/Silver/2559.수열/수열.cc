#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int memo[100010];
int N, K, ans = -99999999;

int main(void)
{
    int i, tot=0;
    scanf("%d %d", &N, &K);

    for(i=1;i<=N;i++) {
        scanf("%d", &memo[i]);
        tot += memo[i];
        if(i>=K) {
            ans = max(ans, tot);
            tot -= memo[i-K+1];
        }
    }

    printf("%d\n", ans);
    return 0;
}
