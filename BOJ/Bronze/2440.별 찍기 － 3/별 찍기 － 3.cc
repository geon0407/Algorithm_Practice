#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    scanf("%d", &n);

    for(n;n>=1;n--) {
        for(i=1;i<=n;i++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
