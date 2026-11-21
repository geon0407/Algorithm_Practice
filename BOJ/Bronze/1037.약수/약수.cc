#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long int arr[50];
long int n;

int main()
{
    scanf("%ld", &n);
    for(long int i=0;i<n;i++) {
        scanf("%ld", &arr[i]);
    }
    sort(arr, arr+n);
    printf("%ld\n", arr[0] * arr[n-1]);
    return 0;
}
