#include <bits/stdc++.h>
using namespace std;

int f();

int n;

int main(void)
{
    scanf("%d", &n);
    int res = f();

    if(res == n) {
        printf("0\n");
    }
    else {
        printf("%d\n", res);
    }

    return 0;
}

int f()
{
    int res = 1;

    while( 1 ) {
        int c = res;
        int sum = res;

        while( c ) {
            sum += c % 10;
            c /= 10;
        }

        if(res == n || sum == n) {
            break;
        }
        res++;
    }

    return res;
}
