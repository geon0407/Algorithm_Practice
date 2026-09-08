#include <bits/stdc++.h>
using namespace std;

char arr[60][60];
int n, m;

int f(int y, int x);

int main(void)
{
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf(" %c", &arr[i][j]);
        }
    }

    int ans = numeric_limits<int>::max();
    for(int i=0;i<n-7;i++) {
        for(int j=0;j<m-7;j++) {
            ans = min(ans, f(i, j));
        }
    }

    printf("%d\n", ans);
    return 0;
}

int f(int y, int x)
{
    int res1=0;
    char key = 'B';
    for(int i=y;i<y+8;i++) {
        for(int j=x;j<x+8;j++) {
            if(key != arr[i][j]) {
                res1++;
            }

            if(j != x+7) {
                key = (key == 'B') ? 'W' : 'B';
            }
        }
    }

    return min(res1, 64-res1);
}
