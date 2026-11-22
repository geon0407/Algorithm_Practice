#include <bits/stdc++.h>
using namespace std;

int m1[110][110], m2[110][110];

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &m1[i][j]);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("%d ", m1[i][j]+m2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
