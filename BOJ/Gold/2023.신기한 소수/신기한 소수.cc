#include <bits/stdc++.h>
using namespace std;

void f(int num, int n, int k);
bool chk(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    
    f(2, n, 1);
    f(3, n, 1);
    f(5, n, 1);
    f(7, n, 1);
    
    return 0;
}

void f(int num, int n, int k)
{
    if(n == k) {
        if(chk(num)) {
            printf("%d\n", num);
        }
        
        return ;
    }
    
    for(int i=1;i<=9;i+=2) {
        if(chk(num)) {
            f(num*10+i, n, k+1);   
        }
    }
    
    return ;
}

bool chk(int n)
{
    for(int i=2;i<=n/2;i++) {
        if(n % i == 0) {
            return false;
        }
    }
    
    return true;
}