#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, f, tmp, i;
    scanf("%d%d", &n, &f);
    n = (n/100)*100;

    for(i=0;i<100;i++) {
        tmp = n;
        if(!((tmp+=i) % f)) {
            break;
        }
    }

    printf("%02d\n", i);
    return 0;
}