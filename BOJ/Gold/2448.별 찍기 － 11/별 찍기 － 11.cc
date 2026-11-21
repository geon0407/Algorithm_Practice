#include <bits/stdc++.h>
using namespace std;

void out(int n, int x, int y);

char ans[4000][7000];

int main(void)
{
    int i, j, n;
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        for(j=0;j<2*n;j++) {
            if(j == 2 * n - 1) {
                ans[i][j] = '\0';
            }
            else {
                ans[i][j] = ' ';
            }
        }
    }

    out(n, n-1, 0);

    for(i=0;i<n;i++) {
        for(j=0;j<2*n-1;j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void out(int n, int x, int y)
{
    if(n == 3) {
        ans[y][x] = '*';
        ans[y+1][x-1] = '*';
        ans[y+1][x+1] = '*';
        ans[y+2][x-2] = '*';
        ans[y+2][x-1] = '*';
        ans[y+2][x] = '*';
        ans[y+2][x+1] = '*';
        ans[y+2][x+2] = '*';

        return ;
    }

    out(n/2, x, y);
    out(n/2, x-(n/2), y+(n/2));
    out(n/2, x+(n/2), y+(n/2));

    return ;
}
