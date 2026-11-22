#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, i;
    double mmax=-1, d=1;
    scanf("%d", &n);
    vector<double> v(n);
    for(i=0;i<n;i++) {
        scanf("%lf", &v[i]);
    }
    
    for(i=0;i<n;i++){
        d *= v[i];
        if(d < 1) {
            d = 1;
        }
        mmax = max(mmax, d);
    }

    double cand = *max_element(v.begin(), v.end());
    if(cand < 1) {
        mmax = cand;
    }
    else {
        mmax = max(cand, mmax);
    }

    printf("%.3lf\n", mmax);
    return 0;
}