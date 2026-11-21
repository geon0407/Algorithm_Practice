#include <bits/stdc++.h>
using namespace std;

int seat[110][110];
int data[110][110];
int ans[110];

void flood_fill(int i, int j, int rain);

int main(void)
{
    int i, j, k, n, maxh=0;
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            scanf("%d", &seat[i][j]);
            maxh = max(maxh, seat[i][j]);
        }
    }

    //printf("maxh : %d\n\n", maxh);
    for(k=0;k<maxh;k++) {
        int cnt=0;
        memset(data, 0, sizeof(data));
        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) {
                if(seat[i][j] > k) {
                    data[i][j] = 1;
                }
            }
        }

        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) {
                if(data[i][j] == 1) {
                    cnt++;
                    flood_fill(i, j, k);
                }
            }
        }

        //printf("k : %d  cnt : %d\n", k, cnt);
        ans[k] = cnt;
    }

    sort(ans, ans+maxh, greater<int>());

    printf("%d\n", ans[0]);
    return 0;
}

void flood_fill(int i, int j, int rain)
{
    data[i][j] = 0;
    if(data[i-1][j] == 1) {
        flood_fill(i-1, j, rain);
    }
    if(data[i+1][j] == 1) {
        flood_fill(i+1, j, rain);
    }
    if(data[i][j-1] == 1) {
        flood_fill(i, j-1, rain);
    }
    if(data[i][j+1] == 1) {
        flood_fill(i, j+1, rain);
    }
}