#include <bits/stdc++.h> 
using namespace std;

void f(int x, int y, int wid);

int d[130][130], ans[2];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> d[i][j];
        }
    }

    f(1, 1, n);

    cout << ans[0] << "\n" << ans[1];
    return 0;
}

void f(int x, int y, int wid)
{
    int tmp = 0;
    for(int i=x;i<x+wid;i++) {
        for(int j=y;j<y+wid;j++) {
            tmp += d[i][j];
        }
    }

    if(tmp == 0) {
        ans[0]++;
    }
    else if(tmp == wid*wid) {
        ans[1]++;
    }
    else {
        wid /= 2;

        f(x, y, wid);
        f(x, y+wid, wid);
        f(x+wid, y, wid);
        f(x+wid, y+wid, wid);
    }

    return ;
}
