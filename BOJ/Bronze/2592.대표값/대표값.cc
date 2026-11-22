#include <bits/stdc++.h>
using namespace std;

int arr[11], cnt[110];

int main(void)
{
    int av = 0;
    for(int i=0;i<10;i++) {
        scanf("%d", &arr[i]);
        cnt[arr[i]/10]++;
        av += arr[i]/10;
    }

    pair<int, int> ans = make_pair(0, 0);
    for(int i=0;i<=100;i++) {
        if(ans.second <= cnt[i]) {
            ans = make_pair(i, cnt[i]);
        }
    }

    printf("%d\n%d\n", av, ans.first*10);
    return 0;
}