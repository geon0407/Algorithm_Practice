#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int Price_1[60];
int Price_6[60];

int main(void)
{
    int N, M, i, pay=0;
    scanf("%d %d", &N, &M);

    for(i=1;i<=M;i++) {
        scanf("%d %d", &Price_6[i], &Price_1[i]);
    }

    sort(Price_1 + 1, Price_1 + M + 1);
    sort(Price_6 + 1, Price_6 + M + 1);

    while(N > 0) {
        if(N >= 6 && Price_6[1] < Price_1[1] * 6) {
            pay += Price_6[1];
            N -= 6;
        }
        else if(N < 6 && Price_6[1] < Price_1[1] * N) {
            pay += Price_6[1];
            N = 0;
        }
        else {
            pay += Price_1[1] * N;
            N = 0;
        }
    }

    printf("%d\n", pay);
    return 0;
}

