#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int i, j, n;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        for(j=0;j<n-i-1;j++) {
            printf(" ");
        }
        for(j=0;j<2*i+1;j++) {
            printf("*");
        }
        printf("\n");
    }
    for(i=0;i<n-1;i++) {
        for(j=0;j<i+1;j++) {
            printf(" ");
        }
        for(j=0;j<2*(n-i-2)+1;j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
