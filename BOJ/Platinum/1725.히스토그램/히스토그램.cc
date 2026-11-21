#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int a[100010];

int main(void)
{
    int n, i;
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }

    int ans = 0;
    for(i=0;i<n;i++) {
        int left = i;
        while(s.size() && a[s.top()] > a[i]) {
            int height = a[s.top()];
            s.pop();
            int width = i;
            if (s.size()) {
                width = (i - s.top() - 1);
            }
            if (ans < width*height) {
                ans = width*height;
            }
        }
        s.push(i);
    }

    while(s.size()) {
        int height = a[s.top()];
        s.pop();

        int width = n;
        if(s.size()) {
            width = n-s.top() - 1;
        }
        if(ans < width*height) {
            ans = width*height;
        }
    }

    printf("%d\n",ans);
    return 0;
}