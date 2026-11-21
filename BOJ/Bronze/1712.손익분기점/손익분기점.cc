#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main(void)
{
    int p;
    scanf("%d%d%d", &a, &b, &c);
    p = c - b;
    if(p <= 0) {
        printf("-1\n");
        exit(0);
    }

    printf("%d\n", (a + p) / p);
    return 0;
}