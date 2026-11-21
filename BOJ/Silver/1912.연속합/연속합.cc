#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int ans[100010];

int main(void)
{
    int N, i, res=-999999999;
    scanf("%d", &N);

    for(i=1;i<=N;i++) {
        scanf("%d", &ans[i]);
        ans[i] = ans[i] + max(0, ans[i-1]);
    }

    for(i=1;i<=N;i++) {
        res = max(res, ans[i]);
    }

    printf("%d\n", res);
    return 0;
}
