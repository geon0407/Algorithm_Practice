#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int l, p;
    scanf("%d %d", &l, &p);
    p *= l;

    for(int i=0;i<5;i++) {
        scanf("%d", &l);
        printf("%d ", l - p);
    }

    return 0;
}
