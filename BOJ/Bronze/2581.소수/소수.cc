#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(void)
{
    int m, n, cnt = 0, num[1229] = { 0 };
    scanf("%d%d", &m, &n);

    if(m <= 1)
    {
        m = 2;
    }

    while(m <= n)
    {
        bool check = false;
        for(int i = 2; i < m; i++)
        {
            if(m % i == 0) check = true;
        }
        if(!check)
        {
            num[cnt++] = m;
        }
        m++;
    }

    int sum = 0;

    for(int i = 0; i < cnt; i++)
        sum += num[i];

    if(sum)
        printf("%d\n%d\n", sum, num[0]);
    else
        printf("-1\n");
    return 0;
}
