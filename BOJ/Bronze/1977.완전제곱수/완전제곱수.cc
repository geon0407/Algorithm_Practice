#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int f(int a);

int start, end, tot, min = 999999;

int main(void)
{
    int i;
    scanf("%d%d", &start, &end);
    for(i=start;i<=end;i++) {
        tot += f(i);
    }
    if(min==999999)
        printf("-1\n");
    else
        printf("%d\n%d\n", tot, min);
    return 0;
}


int f(int a)
{
    if(sqrt(a) / 1.00 == (int)sqrt(a)) {
        if(min > a)
            min = a;
        return a;
    }
    else {
        return 0;
    }
}
