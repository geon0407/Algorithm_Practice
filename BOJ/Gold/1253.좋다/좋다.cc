#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    
    int ans=0;
    for(int i=0;i<n;i++) {
        int st=0, fi=n-1;
        while(st < fi) {
            if(v[st] + v[fi] == v[i]) {
                if(i == st) {
                    st++;
                    continue;
                }
                if(i == fi) {
                    fi--;
                    continue;
                }
                ans++;
                break;
            }
            if(v[st] + v[fi] > v[i]) {
                fi--;
                continue;
            }
            if(v[st] + v[fi] < v[i]) {
                st++;
                continue;
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}