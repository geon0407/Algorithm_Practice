#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int flag=0, sum=0, ans=0, i, in;

    for(i=0;i<8;i++) {
        scanf("%d", &in);
        if(flag == 0) {
            sum-=in;
            if(sum > ans) {
                ans = sum;
            }
            flag = 1;
        }
        else if(flag == 1) {
            sum+=in;
            if(sum > ans) {
                ans = sum;
            }
            flag = 0;
        }
    }

    printf("%d\n", ans);
    return 0;
}
