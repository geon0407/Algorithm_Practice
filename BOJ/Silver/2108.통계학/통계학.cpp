#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int cnt[8010];
int n, tot;

int main(void)
{
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int in;
        scanf("%d", &in);
        cnt[in+4000]++;
        tot += in;
        v.push_back(in);
    }

    sort(v.begin(), v.end());

    printf("%d\n", (int)round((double)tot / n)); //산술평균
    printf("%d\n", v[n/2]); //중앙값

    vector<pair<int, int>> tmp;
    for(int i=0;i<=8000;i++) {
        if(cnt[i]) {
            tmp.push_back(make_pair(cnt[i], i-4000));
        }
    }
    sort(tmp.begin(), tmp.end());

    vector<int> tmp2;
    for(auto i : tmp) {
        //printf("%d %d회\n", i.second, i.first);
        if(i.first == tmp[tmp.size()-1].first) {
            tmp2.push_back(i.second);
        }
    }
    sort(tmp2.begin(), tmp2.end());
    if(tmp2.size() == 1) {
        printf("%d\n", tmp2[0]);
    }
    else {
        printf("%d\n", tmp2[1]);
    }

    printf("%d\n", v[v.size()-1] - v[0]);

    return 0;
}
