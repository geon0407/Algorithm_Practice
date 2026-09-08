#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void calc(int num);

int arr[10];

int main(void)
{
    int i, a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a = a * b * c;
    calc(a);
    for(i=0;i<10;i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

void calc(int num)
{
    while(num > 0) {
        arr[num % 10]++;
        num /= 10;
    }

    return ;
}
