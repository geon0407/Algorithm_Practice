#include <stdio.h>
#include <stdlib.h>

int arr[10010];
int N, M, ans;

int main(void)
{
    int start, finish, i, sum=0;
    scanf("%d %d", &N, &M);

    for(i=0;i<N;i++) {
        scanf("%d", &arr[i]);
    }

    start = finish = 0;

    while( 1 ) {
        if(sum >= M) {
            sum -= arr[start++];
        }
        else if(finish == N) {
            break;
        }
        else {
            sum += arr[finish++];
        }
        if(sum == M) {
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
