#include <bits/stdc++.h>
using namespace std;

vector<int> lec;

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    lec.resize(n);
    
    int st=0, fi=0;
    for(int i=0;i<n;i++) {
        scanf("%d", &lec[i]);
        st = max(st, lec[i]);
        fi += lec[i];
    }
    
    while(st <= fi) {
        int mid = (st + fi) / 2;
        
        int tot=0, cnt=0;
        for(int i=0;i<n;i++) {
            tot += lec[i];
            if(tot > mid) {
                cnt++;
                tot = lec[i];
            }
        }
        
        if(tot) {
            cnt++;
        }
        
        if(cnt <= m) {
            fi = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }
    
    printf("%d\n", st);
    return 0;
}