#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    queue<int> q;
    int i, n, m;
    scanf("%d%d", &n, &m);

    for(i=0;i<n;i++) {
        q.push(i+1);
    }

    printf("<");
    while(q.size()) {
        if(q.size() == 1) {
            printf("%d>", q.front());
            q.pop();
            break;
        }
        for(i=1;i<m;i++) {
            q.push(q.front());
            q.pop();
        }
        printf("%d, ", q.front());
        q.pop();
    }

    printf("\n");
    return 0;
}
