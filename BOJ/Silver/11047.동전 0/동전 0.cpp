#include <stdio.h>
#include <stdlib.h>

int money[15];

int main(void)
{
    int N, K, i, cursor, cnt=0;
    scanf("%d %d", &N, &K);
    cursor = N-1;

    for(i=0;i<N;i++) {
        scanf("%d", &money[i]);
    }

    while( K != 0 ) {
        for(i=cursor;i>=0;i--) {
            if(K >= money[i]) {
                K -= money[i];
                cursor = i;
                cnt++;
                break;
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}
