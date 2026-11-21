#include <bits/stdc++.h>
using namespace std;

int arr[6];
int k, w, h, w2, h2;

int main(void)
{
    scanf("%d", &k);
    for(int i=0;i<6;i++) {
        int dir;
        scanf("%d %d", &dir, &arr[i]);
    }

    for(int i=0;i<6;i++) {
        if(i%2 == 0) {
            w = max(w, arr[i]);
        }
        else {
            h = max(h, arr[i]);
        }
    }

    for(int i=0;i<6;i++) {
        if(i%2 == 0) {
            if(h == arr[(i+5)%6] + arr[(i+1)%6]) {
                w2 = arr[i];
            }
        }
        else {
            if(w == arr[(i+5)%6] + arr[(i+1)%6]) {
                h2 = arr[i];
            }
        }
    }

    printf("%d\n", (w*h - w2*h2) * k);
    return 0;
}
