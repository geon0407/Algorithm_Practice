#include <bits/stdc++.h>

#define INF numeric_limits<int>::max()

using namespace std;

struct Color {
    int r;
    int g;
    int b;
};

Color data[1010];
int DP[1010][5];

int main(void)
{
    int n, i, j, ans=INF;
    scanf("%d", &n);

    for(i=1;i<=n;i++) {
        scanf("%d %d %d", &data[i].r, &data[i].g, &data[i].b);
    }

    for(i=1;i<=n;i++) {
        for(j=1;j<=3;j++) {
            if(j == 1) {
                DP[i][j] += data[i].r + min(DP[i-1][j+1], DP[i-1][j+2]);
            }
            else if(j == 2) {
                DP[i][j] += data[i].g + min(DP[i-1][j-1], DP[i-1][j+1]);
            }
            else {
                DP[i][j] += data[i].b + min(DP[i-1][j-1], DP[i-1][j-2]);
            }
        }
    }

    for(i=1;i<=3;i++) {
        ans = min(ans, DP[n][i]);
    }

    printf("%d\n", ans);
    return 0;
}
