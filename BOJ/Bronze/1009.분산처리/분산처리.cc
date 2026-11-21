#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b;
        scanf("%d%d", &a, &b);

        int res = a%10;
        int mul = b % 4;

        for(int i=1;i<(mul == 0? 4 : mul);i++) {
            res *= a;
            res %= 10;
        }

        res = res ? res : 10;
        printf("%d\n", res);
    }

    return 0;
}