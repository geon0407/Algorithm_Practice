#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t, h, w, n, i;
    scanf("%d", &t);

    for(i=0;i<t;i++) {
        scanf("%d%d%d", &h, &w, &n);
        if(n % h) {
            if(n / h + 1 > 9) {
                printf("%d%d\n", n%h, n/h+1);
            }
            else {
                printf("%d0%d\n", n%h, n/h+1);
            }
        }
        else {
            if(n / h > 9) {
                printf("%d%d\n", h, n/h);
            }
            else {
                printf("%d0%d\n", h, n/h);
            }
        }
    }

    return 0;
}
