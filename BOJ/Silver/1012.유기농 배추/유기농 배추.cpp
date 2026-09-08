#include <stdio.h> 
#include <stdlib.h>
#include <iostream>

using namespace std;

void f(int i, int j);

int arr[100][100];
int ans[2500];
int i, j, k, arri, arrj, cnt, baechu, a, b, c;

int main(void)
{
    scanf("%d", &k);
    while(k!=0) {
        scanf("%d %d %d", &arrj, &arri, &baechu);
        for(i=0;i<baechu;i++) {
            scanf("%d %d", &a, &b);
            arr[b][a] = 1;
        }
        for(i=0;i<arri;i++) {
            for(j=0;j<arrj;j++) {
                if(arr[i][j] == 1) {
                    f(i, j);
                    cnt++;
                }
            }
        }
        k--;
        ans[c] = cnt;
        cnt=0;
        c++;
    }
    for(i=0;i<c;i++)
        printf("%d\n", ans[i]);
    
    return 0;
}

void f(int i, int j)
{
    arr[i][j] = 0;
    if(arr[i-1][j] != 0 && i-1 >= 0)
        f(i-1, j);
    if(arr[i+1][j] != 0)
        f(i+1, j);
    if(arr[i][j-1] != 0 && j-1 >= 0)
        f(i, j-1);
    if(arr[i][j+1] != 0)
        f(i, j+1);
    return ;
}
