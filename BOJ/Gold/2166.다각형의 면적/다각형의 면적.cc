#include <bits/stdc++.h>
using namespace std;

struct data {
    long long int x, y;
};

long long ccw(data p1, data p2, data p3);

data p[10010];

int main(void)
{
    long long ans=0;
    int i, n;
    data f;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }

    f = p[0];
    for(i=1;i<n-1;i++) {
        ans += ccw(f, p[i], p[i+1]);
    }

    if(ans < 0) {
        ans *= -1;
    }

    printf("%lld.", ans/2);
    if(ans % 2) {
        printf("5\n");
    }
    else {
        printf("0\n");
    }

    return 0;
}

long long ccw(data p1, data p2, data p3)
{
    long long a = (p2.x - p1.x) * (p3.y - p1.y);
    long long b = (p2.y - p1.y) * (p3.x - p1.x);

    return a - b;
}