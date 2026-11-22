#include <bits/stdc++.h>
using namespace std;

int arr[10][10];

int main(void)
{
    int maxn=-1, r, c;
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            int in;
            scanf("%d", &in);
            if(in > maxn) {
                maxn = in;
                r = i;
                c = j;
            }
        }
    }

    printf("%d\n%d %d", maxn, r+1, c+1);
    return 0;
}
