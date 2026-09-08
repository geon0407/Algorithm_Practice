#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    if(n == 0) {
        printf("0\n");
        exit(0);
    }

    vector<int> v(n);
    for(int i=0;i<n;i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());

    int range = (int)round((float)n * 0.15);
    int ans = 0;
    for(int i=range;i<n-range;i++) {
        ans += v[i];
    }

    printf("%d\n", (int)round((float)ans / (n-range-range)));
    return 0;
}
