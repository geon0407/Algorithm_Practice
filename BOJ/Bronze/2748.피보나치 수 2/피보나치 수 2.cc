#include <bits/stdc++.h>
using namespace std;

long long int fibo(int n);

long long int memo[100000];
int a;

int main()
{
    scanf("%d", &a);
    printf("%lld\n", fibo(a));
    return 0;
}

long long int fibo(int n)
{
    if(memo[n]) {
        return memo[n];
    }

    if(n<=2) {
        return 1;
    }

    return memo[n] = (fibo(n-1) + fibo(n-2));
}