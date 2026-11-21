#include <bits/stdc++.h>
using namespace std;

void f(int i, int j, int k);

int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            f(i, j, n);
        }
        cout << "\n";
    }
}

void f(int i, int j, int k)
{
    if((i/k)%3 == 1 && (j/k)%3 == 1) {
        cout << " ";
    }
    else {
        if(k/3 == 0) {
            cout << "*";
        }
        else {
            f(i, j, k/3);
        }
    }

    return ;
}
