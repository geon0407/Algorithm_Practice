#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int GCD(int a, int b);
int LCM(int a, int b);

int main(void)
{
    int i, t;
    scanf("%d", &t);
    for(i=0;i<t;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", LCM(a, b));
    }
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
