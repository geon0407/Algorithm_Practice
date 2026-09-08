#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int check(int number);

int main(void)
{
    int n, num, i, ans=0;
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        scanf("%d", &num);
        ans += check(num);
    }

    printf("%d\n", ans);
    return 0;
}

int check(int number)
{
    int i;
    if(number == 1) {
        return 0;
    }

    for(i=2;i<=number-1;i++) {
        if(number % i == 0) {
            return 0;
        }
    }

    return 1;
}
