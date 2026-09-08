#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int Sugar, ans = 9999999;

int main(void)
{
    int i, j;
    scanf("%d", &Sugar);

    for(i=0;i<=1000;i++) {
        for(j=0;j<=1667;j++) {
            if(5*i+3*j == Sugar) {
                ans = min(ans, i+j);
            }
        }
    }

    if(ans == 9999999) {
        printf("-1\n");
    }
    else {
        printf("%d\n", ans);
    }
    return 0;
}
