#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, in, ans=0;

    for(i=0;i<5;i++) {
        scanf("%d", &in);
        ans+=in*in;
    }

    printf("%d\n", ans % 10);
    return 0;
}
