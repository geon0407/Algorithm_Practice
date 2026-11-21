#include <bits/stdc++.h>
using namespace std;

int n;

int main(void)
{
    scanf("%d", &n);
    
    int st=1, fi=1, sum=1, ans=1;
    while(st != n) {
        if(sum == n) {
            ans++;
            sum -= st++;
            continue;
        }
        
        if(sum < n) {
            sum += ++fi;
            continue;
        }
        
        if(sum > n) {
            sum -= st++;
            continue;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}