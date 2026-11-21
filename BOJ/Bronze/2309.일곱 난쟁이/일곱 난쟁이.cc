#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int f(int i, int select, int sum) ;

int arr[9], ans[7];

int main(void)
{
    int i;
    for(i=0;i<9;i++) {
        scanf("%d", &arr[i]);
    }
    f(0,0,0);
    sort(ans, ans+7);
    for(i=0;i<7;i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
int f(int i, int select, int sum)
{
    if(select == 7) {
        if(sum == 100) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if(i>=9)
        return 0;
    if(f(i+1, select+1, sum+arr[i]) == 1) {
        ans[select] = arr[i];
        return 1;
    }
    if(f(i+1, select, sum) == 1) {
        return 1;
    }
    return 0;
}
