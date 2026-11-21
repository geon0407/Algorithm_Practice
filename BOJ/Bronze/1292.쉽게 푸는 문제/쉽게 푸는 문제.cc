#include <bits/stdc++.h>
using namespace std;

int arr[1010];

int main(void)
{
    int a, b, cur=1, tot=0;
    scanf("%d%d", &a, &b);

    for(int i=1;i<=1000;i++) {
        for(int j=1;j<=i;j++) {
            arr[cur++] = i;
            if(cur > 1000) {
                break;
            }
        }
    }

    for(int i=a;i<=b;i++) {
        tot += arr[i];
    }
    printf("%d\n", tot);
    return 0;
}