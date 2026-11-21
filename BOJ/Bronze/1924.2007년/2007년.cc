#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char ans[10][10] {
    "SUN",
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT"
} ;

int main(void)
{
    int i, x, y, day=0;
    scanf("%d%d", &x, &y);
    for(i=1;i<x;i++) {
        day+=month[i];
    }
    day += y;
    printf("%s\n", ans[day%7]);
    return 0;
}
