#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int ans[30];
char arr[110];

int main(void)
{
    int i;
    scanf("%s", arr);

    for(i=0;i<30;i++) {
        ans[i] = 999;
    }

    for(i=0;i<strlen(arr);i++) {
        ans[arr[i]-'a'] = min(i, ans[arr[i]-'a']);
    }

    for(i=0;i<26;i++) {
        if(ans[i] == 999) {
            printf("-1 ");
        }
        else {
            printf("%d ", ans[i]);
        }
    }

    printf("\n");
    return 0;
}
