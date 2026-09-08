#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int stair[310], DP[310];
int N;

int main(void)
{
    int i;
    scanf("%d", &N);

    for(i=1;i<=N;i++) {
        scanf("%d", &stair[i]);
    }

    for(i=1;i<=3&&i<=N;i++) {
        if(i!=3) {
            DP[i] = DP[i-1] + stair[i];
        }
        else {
            DP[i] = max(stair[i] + DP[i-2], stair[i] + stair[i-1]);
        }
    }

    for(i=4;i<=N;i++) {
        DP[i] = max(stair[i] + DP[i-2], stair[i] + stair[i-1] + DP[i-3]);
    }

    printf("%d\n", DP[N]);
    return 0;
}
