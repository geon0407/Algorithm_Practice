#include <bits/stdc++.h>
using namespace std;

int chk[10][10];
char line[10];

int main(void)
{
    int i, j, flag = 1;
    for(i=0;i<8;i++) {
        flag = flag > 0 ? -1 : 1;
        for(j=0;j<8;j++) {
            chk[i][j] = flag;
            flag = -flag;
        }
    }

    flag = 0;
    for(i=0;i<8;i++) {
        scanf("%s", line);
        for(j=0;j<8;j++) {
            if(line[j] == 'F' && chk[i][j] < 0) {
                flag++;
            }
        }
    }

    printf("%d\n", flag);
    return 0;
}
