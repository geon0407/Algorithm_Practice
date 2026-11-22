#include <bits/stdc++.h>
using namespace std;

int arr[5];

int main(void)
{
    int avg=0;
    for(int i=0;i<5;i++) {
        scanf("%d", &arr[i]);
        avg += arr[i];
    }
    sort(arr, arr+5);

    printf("%d\n%d", avg/5, arr[2]);
    return 0;
}
