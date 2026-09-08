#include <bits/stdc++.h> 
using namespace std;

vector<int> v;
vector<int> ans;

int main(void)
{
    int n, i;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        int in;
        scanf("%d", &in);
        v.push_back(in);
        ans.push_back(in);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for(i=0;i<n;i++) {
        printf("%d ", lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin());
    }
    return 0;
}
