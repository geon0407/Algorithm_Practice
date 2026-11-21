#include <bits/stdc++.h>
using namespace std;

int arr[10];
int n;

int main(void)
{
    int i, ans = 0;
    scanf("%d", &n);
    while( 1 ) {
        arr[n % 10]++;
        if(n / 10 == 0) {
            break;
        }
        n /= 10;
    }

    for(i=0;i<10;i++) {
        if(i == 6 || i == 9) {
            continue;
        }
        ans = max(arr[i], ans);
    }

    printf("%d\n", max((arr[6] + arr[9] + 1) / 2, ans));
    return 0;
}
