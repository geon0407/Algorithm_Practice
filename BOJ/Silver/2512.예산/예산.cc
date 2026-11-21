#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int n, m;

int main(void)
{
    int i, maxB;
    scanf("%d", &n);
    vector<int> arr(n);

    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
        maxB = max(maxB, arr[i]);
    }

    scanf("%d", &m);

    int res, l=0, h=maxB;
    while(l <= h) {
        long long int tot = 0;
        int mid = (l + h) / 2;
        for(i=0;i<n;i++) {
            tot += min(arr[i], mid);
        }
        if(tot <= m) {
            res = mid;
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }

    printf("%d\n", res);
    return 0;
}