#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i;
    cin >> n;

    vector<pair<int, string>> data(n);

    for(i=0;i<n;i++) {
        cin >> data[i].first >> data[i].second;
    }

    stable_sort(data.begin(), data.end(), cmp);

    for(i=0;i<n;i++) {
        cout << data[i].first << " " << data[i].second << "\n";
    }

    return 0;
}
