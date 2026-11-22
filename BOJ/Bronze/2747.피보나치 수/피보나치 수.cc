#include <bits/stdc++.h>
using namespace std;

int fibo(int n);

int memo[50] = {0, 1, 1, 2, };

int main(void)
{
    int N;
    scanf("%d", &N);
    printf("%d\n", fibo(N));
}

int fibo(int n)
{
    if(memo[n] != 0) {
        return memo[n];
    }

    return memo[n] = fibo(n-1) + fibo(n-2);
}