#include <bits/stdc++.h>
using namespace std;

int i, j, t_size, ans;
int t[550][550];
int s[550][550];

int main(void)
{
    scanf("%d", &t_size);

    for(i=0;i<t_size;i++) {
        for(j=0;j<=i;j++) {
            scanf("%d", &t[i][j]);
        }
    }

    for(i=0;i<=t_size-1;i++) {
        for(j=0;j<=i;j++) {
            if(i==0 && j==0) {
                s[0][0] = t[0][0];
            }
            else if(j==0) {
                s[i][0] = t[i][0] + s[i-1][0];
            }
            else if(i==j) {
                s[i][j] = t[i][j] + s[i-1][j-1];
            }
            else {
                s[i][j] = t[i][j] + max(s[i-1][j-1], s[i-1][j]);
            }
        }
    }

    for(j=0;j<t_size;j++) {
        if(ans < s[t_size-1][j]) {
            ans = s[t_size-1][j];
        }
    }

    printf("%d\n", ans);
    return 0;
}
