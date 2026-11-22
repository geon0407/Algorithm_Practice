#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n2[5];
    int n1, i, ans=0;
    scanf("%d", &n1);
    for(i=0;i<3;i++) {
        scanf("%1d", &n2[i]);
    }

    for(i=2;i>=0;i--) {
        printf("%d\n", n2[i]*n1);
    }

    ans = n1*n2[2] + n1*n2[1]*10 + n1*n2[0]*100;
    printf("%d\n", ans);
    return 0;
}
