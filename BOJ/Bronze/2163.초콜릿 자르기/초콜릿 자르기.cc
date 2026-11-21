#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", a-1 + (b-1)*a);

    return 0;
}
