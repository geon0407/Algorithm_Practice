#include <stdio.h>  
#include <stdlib.h>

int Fibo[50] = {0, 1, };

int main(void)
{
    int T, N, i;
    scanf("%d", &T);

    for(i=2;i<=40;i++) {
        Fibo[i] = Fibo[i-1] + Fibo[i-2];
    }

    for(i=0;i<T;i++) {
        scanf("%d", &N);
        if(N == 0) {
            printf("1 0\n");
        }
        else if(N == 1) {
            printf("0 1\n");
        }
        else {
            printf("%d %d\n", Fibo[N-1], Fibo[N]);
        }
    }

    return 0;
}
