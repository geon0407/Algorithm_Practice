#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int x, i=1;
    scanf("%d", &x);

    while(x > i) {
        x -= i;
        i++;
    }

    if(i % 2) {
        printf("%d/%d", i+1-x, x);
    }
    else {
        printf("%d/%d", x, i+1-x);
    }

    return 0;
}