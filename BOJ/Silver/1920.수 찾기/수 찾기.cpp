#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> v;
    int n;

    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int in;
        scanf("%d", &in);
        v.push_back(in);
    }
    sort(v.begin(), v.end());

    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int in;
        scanf("%d", &in);
        printf("%d\n", binary_search(v.begin(), v.end(), in));
    }

    return 0;
}
