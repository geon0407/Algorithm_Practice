#include <stdio.h> 
#include <stdlib.h>
#include <algorithm>

using namespace std;

void f(int y, int x, int num);

char Map[30][30];
int ans[400];
int Map_Size;

int main(void)
{
    int i, j, apt_num=0;
    scanf("%d", &Map_Size);
    for(i=0;i<Map_Size;i++) {
        scanf("%s", Map[i]);
    }
    for(i=0;i<Map_Size; i++) {
        for(j=0;j<Map_Size;j++) {
            if(Map[i][j]=='1') {
                f(i, j, apt_num);
                apt_num++;
            }
        }
    }
    sort(ans, ans+apt_num);
    printf("%d\n", apt_num);
    for(i=0;i<apt_num;i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
void f(int y, int x, int num)
{
    Map[y][x] = '0';
    ans[num]++;
    if(y-1>=0 && Map[y-1][x] == '1')
        f(y-1, x, num);
    if(y+1<=Map_Size && Map[y+1][x] == '1')
        f(y+1, x, num);
    if(x-1>=0 && Map[y][x-1] == '1')
        f(y, x-1, num);
    if(x+1<=Map_Size && Map[y][x+1] == '1')
        f(y, x+1, num);
}
