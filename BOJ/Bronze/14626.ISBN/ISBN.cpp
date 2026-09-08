#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int sum = 0, chk;
    for(int i=0;i<13;i++) {
        char ch;
        scanf("%c", &ch);

        if(ch == '*') {
            chk = !(i % 2) ? 1 : 3;
            continue;
        }

        sum += (!(i % 2) ? (int)(ch - '0') : (int)(ch - '0') * 3);
    }

    for(int i=0;i<=9;i++) {
        if((chk*i + sum) % 10 == 0) {
            printf("%d\n", i);
            exit(0);
        }
    }

    return 0;
}
