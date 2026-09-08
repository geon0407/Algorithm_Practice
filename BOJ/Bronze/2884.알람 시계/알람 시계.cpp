#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int h, m;
    scanf("%d%d", &h, &m);

    int ansh, ansm;
    if(m < 45) {
        ansm = m + 15;
        ansh = h - 1;
        if(ansh < 0) {
            ansh = 23;
        }
    }
    else {
        ansm = m - 45;
        ansh = h;
    }

    printf("%d %d\n", ansh, ansm);
    return 0;
}
