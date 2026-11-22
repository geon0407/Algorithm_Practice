#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

void DFS(int sp, int cnt);

vector<int> path;
int in[110];
int check[110];
int start;

int main(void)
{
    int n, i;
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        scanf("%d", &in[i]);
    }

    for(i=1;i<=n;i++) {
        if(check[i] == 0) {
            start = i;
            DFS(start, 1);
        }
    }

    sort(path.begin(), path.end());
    printf("%d\n", path.size());
    for(i=0;i<path.size();i++) {
        printf("%d\n", path[i]);
    }

    return 0;
}

void DFS(int sp, int cnt)
{
    int i;

    check[sp] = 1;
    path.push_back(sp);

    if(in[sp] == start && check[in[sp]] == 1) {
        return ;
    }
    if(in[sp] != start && check[in[sp]] == 1) {
        for(i=0;i<cnt;i++) {
            int tmp = path.back();
            path.pop_back();
            check[tmp] = 0;
        }
        return ;
    }
    if(check[in[sp]] == 0) {
        DFS(in[sp], cnt+1);
    }
}
