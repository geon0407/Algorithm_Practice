#include <bits/stdc++.h> 
using namespace std;

int num[1000010];

int main(void)
{
    int i, j, m, n;
    scanf("%d%d", &m, &n);

    for(i=2;i<=n;i++) {
        for(j=i;j<=n;j+=i) {
            num[j]++;
        }
    }

    for(i=m;i<=n;i++) {
        if(num[i] == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}
