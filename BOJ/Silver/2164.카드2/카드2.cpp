#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i=1;i<=n;i++) {
        q.push(i);
    }

    while(q.size() != 1) {
        int tmp;
        q.pop();
        tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    printf("%d\n", q.front());
    return 0;
}
