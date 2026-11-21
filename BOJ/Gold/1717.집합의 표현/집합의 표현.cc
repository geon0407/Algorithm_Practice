#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int find_root(int p);
void union_set(int s1, int s2);

int root[1000010];

int main(void)
{
    int i, n, m;
    scanf("%d %d", &n, &m);
    for(i=0;i<=n;i++) {
        root[i] = i;
    }

    for(i=0;i<m;i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if(a == 0) {
            union_set(b, c);
        }
        else {
            if(find_root(b) == find_root(c)) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
    }

    return 0;
}

int find_root(int p)
{
    if(p == root[p]) {
        return p;
    }

    return root[p] = find_root(root[p]);
}

void union_set(int s1, int s2)
{
    s1 = find_root(s1);
    s2 = find_root(s2);

    if(s1 == s2) {
        return ;
    }

    if(s1 > s2) {
        swap(s1, s2);
    }

    root[s2] = s1;

    return ;
}
