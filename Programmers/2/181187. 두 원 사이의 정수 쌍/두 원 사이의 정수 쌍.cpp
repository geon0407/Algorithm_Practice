#include <bits/stdc++.h>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for(int x=1;x<=r2;x++) {
        long long ymax = floor(sqrt(1LL*r2*r2 - 1LL*x*x));
        long long ymin = 0;

        if (x < r1) {
            ymin = ceil(sqrt(1LL*r1*r1 - 1LL*x*x));
        }

        answer += (ymax - ymin + 1);
    }

    return 4*answer;
}