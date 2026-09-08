#include <bits/stdc++.h> 

#define R 1
#define G 2
#define B 3

using namespace std;

void flood_ab(int y, int x, int key);
void flood_dis(int y, int x, int key);

int ab[110][110];
int disab[110][110];

int main(void)
{
    int n, i, j, ans_ab=0, ans_dis=0;
    scanf("%d", &n);

    for(i=1;i<=n;i++) {
        char in[110];
        scanf("%s", in);
        for(j=1;j<=n;j++) {
            if(in[j-1] == 'R') {
                ab[i][j] = R;
                disab[i][j] = R;
            }
            else if(in[j-1] == 'G') {
                ab[i][j] = G;
                disab[i][j] = R;
            }
            else {
                ab[i][j] = B;
                disab[i][j] = B;
            }
        }
    }

    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            if(ab[i][j] != 0) {
                flood_ab(i, j, ab[i][j]);
                ans_ab++;
            }
            if(disab[i][j] != 0) {
                flood_dis(i, j, disab[i][j]);
                ans_dis++;
            }

        }
    }

    printf("%d %d\n", ans_ab, ans_dis);
    return 0;
}

void flood_ab(int y, int x, int key)
{
    ab[y][x] = 0;

    if(ab[y-1][x] == key) {
        flood_ab(y-1, x, key);
    }
    if(ab[y+1][x] == key) {
        flood_ab(y+1, x, key);
    }
    if(ab[y][x-1] == key) {
        flood_ab(y, x-1, key);
    }
    if(ab[y][x+1] == key) {
        flood_ab(y, x+1, key);
    }

    return ;
}

void flood_dis(int y, int x, int key)
{
    disab[y][x] = 0;

    if(disab[y-1][x] == key) {
        flood_dis(y-1, x, key);
    }
    if(disab[y+1][x] == key) {
        flood_dis(y+1, x, key);
    }
    if(disab[y][x-1] == key) {
        flood_dis(y, x-1, key);
    }
    if(disab[y][x+1] == key) {
        flood_dis(y, x+1, key);
    }

    return ;
}
