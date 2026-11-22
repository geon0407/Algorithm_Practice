#include <bits/stdc++.h>
using namespace std;

int arr[101][101];

int main(void)
{
    int i, j, k;
    int n;
    int x, y;
    int sum = 0;
    scanf("%d", &n);


    for(i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        for(j = x; j < x + 10; j++) {
            for(k = y; k < y + 10; k++) {
                arr[j][k] = 1;
            }
        }
    }

    for(i = 0; i < 100; i++) {
        for(j = 0; j < 100; j++) {
            sum += arr[i][j];
        }
    }

    printf("%d", sum);
    return 0;
}