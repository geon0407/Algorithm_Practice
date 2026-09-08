#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, in, ans_fig=0, ans_num=0;
    for(i=0;i<9;i++) {
        scanf("%d", &in);
        if(ans_fig < in) {
            ans_fig = in;
            ans_num = i+1;
        }
    }

    printf("%d\n%d\n", ans_fig, ans_num);
    return 0;
}
