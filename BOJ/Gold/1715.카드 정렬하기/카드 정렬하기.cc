#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    scanf("%d", &n);
    
    for(int i=0;i<n;i++) {
        int in;
        scanf("%d", &in);
        q.push(in);
    }
    
    int ans=0;
    while(q.size() > 1) {
        int a, b;
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        
        ans += (a + b);
        q.push(a + b);
    }
    
    printf("%d\n", ans);
    return 0;
}