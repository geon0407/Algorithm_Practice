#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(void)
{
    int d1, d2, d3, ans;
    scanf("%d %d %d", &d1, &d2, &d3);

    if(d1 == d2 && d2 == d3) {
        ans = d1 * 1000 + 10000;
    }
    else if(d1 != d2 && d2 != d3 && d3 != d1) {
        ans = max(d1, max(d2, d3)) * 100;
    }
    else {
        if(d1 == d2) {
            ans = d1 * 100 + 1000;
        }
        else if(d2 == d3) {
            ans = d2 * 100 + 1000;
        }
        else {
            ans = d3 * 100 + 1000;
        }
    }

    printf("%d\n", ans);
    return 0;
}
