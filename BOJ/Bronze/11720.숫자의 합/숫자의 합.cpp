#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int i, in, cnt=0;
    scanf("%d", &i);

    for(i;i>=1;i--) {
        scanf("%1d", &in);
        cnt+=in;
    }

    printf("%d\n", cnt);
    return 0;
}
