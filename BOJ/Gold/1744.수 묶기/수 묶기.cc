#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	priority_queue<int> plus;
	priority_queue<int, vector<int>, greater<int>> minus;
	int n, zero=0, one=0;

	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int in;
		scanf("%d", &in);

		if(in < 0) {
			minus.push(in);
		}
		else if(in == 0) {
			zero++;
		}
		else if(in == 1) {
			one++;
		}
		else {
			plus.push(in);
		}
	}

	int ans=0;
	while(!plus.empty()) {
		if(plus.size() == 1) {
			ans += plus.top();
			plus.pop();
			continue;
		}

		int a, b;

		a = plus.top();
		plus.pop();
		b = plus.top();
		plus.pop();

		ans += (a * b);
	}

	while(!minus.empty()) {
		if(minus.size() == 1) {
			if(zero) {
				minus.pop();
				continue;
			}

			ans += minus.top();
			minus.pop();
			continue;
		}

		int a, b;
		a = minus.top();
		minus.pop();
		b = minus.top();
		minus.pop();

		ans += (a * b);
	}
    
	printf("%d\n", ans + one);
	return 0;
}