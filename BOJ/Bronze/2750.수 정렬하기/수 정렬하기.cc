#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int arr[2020];

int main(void)
{
    int i, n;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        int in;
        scanf("%d", &in);
        if(in < 0) {
            in = 1000 - in;
        }
        arr[in]++;
    }
    for(i=2000;i>=1001;i--) {
        if(arr[i] != 0) {
            printf("%d\n", -i+1000);
        }
    }
    for(i=0;i<=1000;i++) {
        if(arr[i] != 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}
