#include <bits/stdc++.h>
using namespace std;

int arr[3];

int main(void)
{
    for(int i=0;i<3;i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+3);
    for(int i=0;i<3;i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}