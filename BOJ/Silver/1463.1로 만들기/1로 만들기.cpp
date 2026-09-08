#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int DP[1000010];

int main(void)
{
    int i, N;
    scanf("%d", &N);

    DP[1] = 0;

    for(i=2;i<=N;i++) {
        DP[i] = DP[i-1] + 1;
        if(i % 2 == 0) {
            DP[i] = min(DP[i], DP[i/2] + 1);
        }
        if(i % 3 == 0) {
            DP[i] = min(DP[i], DP[i/3] + 1);
        }
    }

    printf("%d\n", DP[N]);
    return 0;
}
