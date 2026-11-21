#include <bits/stdc++.h>
using namespace std;

long long int arr[100];

int main(void)
{
    int i, n;
    scanf("%d", &n);

    arr[0] = 0;
    arr[1] = 1;
    for(i=2;i<=n;i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    printf("%lld\n", arr[n]);
    return 0;
}