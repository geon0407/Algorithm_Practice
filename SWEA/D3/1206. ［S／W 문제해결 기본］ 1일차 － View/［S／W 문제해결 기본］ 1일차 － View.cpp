#include <bits/stdc++.h>
using namespace std;

void solve(int tc);

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        solve(test_case);
	}

	return 0;
}

void solve(int tc)
{
    int n, ans=0;
    cin >> n;

    vector<int> b;

    b.push_back(0);
    b.push_back(0);
    for(int i=0;i<n;i++) {
        int in;
        cin >> in;
        b.push_back(in);
    }
    b.push_back(0);
    b.push_back(0);

    for(int i=2;i<n+2;i++) {
        int tmp = max(b[i-2], max(b[i-1], max(b[i+1], b[i+2])));
        ans += max(0, b[i] - tmp);
    }

    cout << "#" << tc << " " << ans << "\n";
    return ;
}