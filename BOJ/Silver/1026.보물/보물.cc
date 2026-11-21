#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <algorithm>

using namespace std;

int N;
int A[110];
int B[110];

int main(void)
{
    int i, ans=0;
    scanf("%d", &N);

    for(i=0;i<N;i++) {
        scanf("%d", &A[i]);
    }
    for(i=0;i<N;i++) {
        scanf("%d", &B[i]);
    }

    sort(A, A+N);
    sort(B, B+N, greater<int>());

    for(i=0;i<N;i++) {
        ans += A[i] * B[i];
    }

    printf("%d\n", ans);
    return 0;
}
