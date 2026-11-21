#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

pair<int, int> Data[100010];

int main(void)
{
    int N, i, j;
    scanf("%d", &N);

    for(i=0;i<N;i++) {
        int sm, sd, lm, ld;
        scanf("%d %d %d %d", &sm, &sd, &lm, &ld);

        Data[i].first = sm * 100 + sd;
        Data[i].second = lm * 100 + ld;
    }

    sort(Data, Data+N);

    int date = 301, flag, temp, ans;
    i=-1;
    flag = temp = ans = 0;

    while(date <= 1130 && i < N) {
        flag = 0;
        i++;
        for(j=i;j<N;j++) {
            if(Data[j].first > date) {
                break;
            }
            if(temp < Data[j].second) {
                temp = Data[j].second;
                flag = 1;
                i = j;
            }
        }
        if(flag) {
            date = temp;
            ans++;
        }
        else {
            printf("0\n");
            return 0;
        }
    }

    printf("%d\n", ans);
    return 0;
}
