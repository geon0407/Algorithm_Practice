#include <bits/stdc++.h>
using namespace std;

int seat[105][105];

int main(void)
{
    int i, j, k, x1, y1, x2, y2, cnt=0;

    for(i=0;i<105;i++) {
        for(j=0;j<105;j++) {
            seat[i][j] = 0;
        }
    }


    for(i=0;i<4;i++){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for(j=x1;j<x2;j++) {
            for(k=y1;k<y2;k++) {
                seat[j][k] = 1;
            }
        }
    }

    for(i=1;i<=100;i++) {
        for(j=1;j<=100;j++) {
            cnt += seat[i][j];
        }
    }

    printf("%d\n",cnt);
    return 0;
}