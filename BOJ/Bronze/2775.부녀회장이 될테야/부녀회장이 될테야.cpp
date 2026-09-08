#include <bits/stdc++.h> 
using namespace std; 

int arr[20][20];
int t, h, w;

int main(void)
{
    scanf("%d", &t);

    for(int i=0;i<15;i++) {
        arr[0][i] = i;
    }

    for(int i=1;i<15;i++) {
        for(int j=1;j<15;j++) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    while(t--) {
        scanf("%d%d", &h, &w);
        printf("%d\n", arr[h][w]);
    }

    return 0;
}
