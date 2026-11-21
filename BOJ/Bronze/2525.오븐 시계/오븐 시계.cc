#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int a, b, c;

int main(void)
{
    scanf("%d %d %d", &a, &b, &c);

    b += c;

    a += b / 60;

    b = b % 60;

    a = a % 24;

    printf("%d %d\n", a, b);

    return 0;
}
