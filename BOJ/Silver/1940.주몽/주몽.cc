#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(void)
{
    scanf("%d%d", &n, &m);
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    
    int st=0, fi=n-1, ans=0;
    while(st < fi) {
        if(arr[st] + arr[fi] == m) {
            ans++;
            st++;
            fi--;
            continue;
        }
        
        if(arr[st] + arr[fi] > m) {
            fi--;
            continue;
        }
        
        if(arr[st] + arr[fi] < m) {
            st++;
            continue;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}