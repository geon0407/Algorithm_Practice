#include <stdio.h>
#include <stdlib.h>

struct stick {
    int length;
    int way;
};

int N, L, ans;

stick ladder[3010];

int main(void)
{
    int i;
    scanf("%d %d", &N, &L);

    for(i=1;i<=N;i++) {
        scanf("%d %d", &ladder[i].length, &ladder[i].way);
    }

    for(i=2;i<=N;i++) {
        if(ladder[i].way != ladder[i-1].way) {
            if(L-ladder[i].length-ladder[i-1].length > ans) {
                ans = L-ladder[i].length-ladder[i-1].length;
            }
        }
    }

    printf("%d\n", ans/2);
    return 0;
}
