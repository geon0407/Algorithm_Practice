#include <bits/stdc++.h>
using namespace std;

int weight[30];
int marble[30];
int flag[50][15010];
int wcnt, mcnt;

void calc(int n, int w);

int main(void)
{
    int i;
    scanf("%d", &wcnt);
    for(i=0;i<wcnt;i++) {
        scanf("%d", &weight[i]);
    }
    scanf("%d", &mcnt);
    for(i=0;i<mcnt;i++) {
        scanf("%d", &marble[i]);
    }

    memset(flag, -1, sizeof(flag));
    calc(0, 0);

    for(i=0;i<mcnt;i++) {
        if(marble[i] > 15000) {
            printf("N ");
        }
        else if(flag[wcnt][marble[i]] == 1) {
            printf("Y ");
        }
        else {
            printf("N ");
        }
    }

    return 0;
}

void calc(int n, int w)
{
    int &res = flag[n][w];

    if(n > wcnt) {
        return ;
    }
    if(res != -1) {
        return ;
    }

    flag[n][w] = 1;

    calc(n+1, w+weight[n]);
    calc(n+1, w);
    calc(n+1, abs(w - weight[n]));

    return ;
}