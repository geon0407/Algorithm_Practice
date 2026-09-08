#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void f(int here);

int Connect_Map[101][101];
int went[100];
int computer, network, cnt;

int main(void)
{
    int i, a, b;
    scanf("%d%d", &computer, &network);
    for(i=0;i<network;i++) {
        scanf("%d%d", &a, &b);
        Connect_Map[a][b] = 1;
        Connect_Map[b][a] = 1;
    }
    f(1);
    printf("%d\n", cnt-1);
}

void f(int here)
{
    int there;
    cnt++;
    went[here] = 1;
    for(there=1;there<=computer;there++) {
        if(Connect_Map[here][there] == 1 && went[there] == 0)
            f(there);
    }
}
