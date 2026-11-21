#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, stick=64, ans=0;
    scanf("%d", &n);
    while(n > 0) {
        if(stick > n) {
            stick /= 2;
        }
        else {
            ans++;
            n -= stick;
        }
    }

    printf("%d\n", ans);
    return 0;
}
