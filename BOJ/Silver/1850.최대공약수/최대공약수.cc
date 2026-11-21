#include <bits/stdc++.h>
using namespace std;

long gcd(long a, long b);

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    long a, b, tmp;
    cin >> a >> b;
    
    tmp = gcd(a, b);
    while(tmp > 0) {
        cout << 1;
        tmp--;
    }
    
    return 0;    
}

long gcd(long a, long b)
{
    if(!b) {
        return a;
    }
    
    return gcd(b, a%b);
}