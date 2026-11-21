#include <bits/stdc++.h>
using namespace std;

long long check[10];

void calc(long long n, long long ten);
void solve(long long a, long long b, long long ten);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    solve(1, n, 1);

    for(auto cnt : check) {
        cout << cnt << ' ';
    }

    return 0;
}

void calc(long long n, long long ten)
{
    while(n > 0) {
        check[n%10] += ten;
        n /= 10;
    }
    
    return ;
}

void solve(long long a, long long b, long long ten)
{
    while(a <= b && a%10 != 0) {
        calc(a, ten);
        a++;
    }

    if(a > b) {
        return;
    }

    while(b >= a && b%10 != 9) {
        calc(b, ten);
        b--;
    }

    long long cnt = b/10 - a/10 + 1;
    for(int i=0;i<10;i++) {
        check[i] += cnt * ten;
    }

    solve(a/10, b/10, ten*10);
    
    return ;
}