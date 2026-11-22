#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int arr[100000];
int n, p, target, ans;

int f(int index ,int cnt);

int main(void)
{
    scanf("%d %d", &n, &p);
    target = n * n % p;
    arr[n]++;
    while(1) {
        arr[target]++;
        if(arr[target] == 3) {
            ans = f(target * n % p, 1);
            break;
        }
        target = target * n % p;
    }
    printf("%d\n", ans);

    return 0;
}
int f(int index, int cnt)
{
    arr[index]++;
    if(arr[index] == 4)
        return cnt;
    return f(index * n % p, cnt+1);
}
