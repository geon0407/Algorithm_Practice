#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    
    int st=1, fi=k;
    while(st <= fi) {
        int mid = (st + fi) / 2;
        
        int sum = 0;
        int range = min(mid, n);
        for(int i=1;i<=range;i++) {
            sum += min(mid / i, n);
        }
        
        if(sum < k) {
            st = mid + 1;
        }
        else {
            fi = mid - 1;
        }
    }
    
    printf("%d\n", st);
    return 0;
}