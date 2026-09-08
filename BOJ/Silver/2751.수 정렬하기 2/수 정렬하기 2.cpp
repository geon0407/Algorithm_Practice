#include <stdio.h> 
#include <stdlib.h>
#include <algorithm>

using namespace std; 

int arr[1001010];
int N;

int main(void)
{
    int i;
    scanf("%d", &N);

    for(i=0;i<N;i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+N);

    for(i=0;i<N;i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
