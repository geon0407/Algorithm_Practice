#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

pair<int, int> Data[15];
int people, ans_max;

int main(void)
{
    int i;

    for(i=1;i<=10;i++) {
        scanf("%d %d", &Data[i].first, &Data[i].second);
        people -= Data[i].first;
        people += Data[i].second;
        ans_max = max(ans_max, people);
    }

    printf("%d\n", ans_max);
    return 0;
}
