#include <stdio.h>

int cnt[10001];

int main(void)
{
    int n;
    int v=0;
    scanf("%d",&n);
 
    for(int i=0; i<n; i++)
    {
        scanf("%d",&v);
        cnt[v]++;
    }
 
    for(int i=1; i<=10000; i++)
    {
        if(cnt[i] >0)
            for(int j=0; j<cnt[i]; j++)
                printf("%d\n",i);
    }
 
 
    return 0;
}
