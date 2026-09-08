#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b);
int LCM(int a, int b);

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n%d\n", GCD(a, b), LCM(a, b));
    return 0;
}

int GCD(int a, int b)
{
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}
