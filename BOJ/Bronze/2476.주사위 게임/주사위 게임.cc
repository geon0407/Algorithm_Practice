#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int score[1010];
int n;

int main(void)
{
    int i;
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        int d1, d2, d3;
        scanf("%d %d %d", &d1, &d2, &d3);

        if(d1 == d2 && d2 == d3) {
            score[i] = d1 * 1000 + 10000;
        }
        else if(d1 == d2 || d2 == d3 || d3 == d1) {
            if(d1 == d2) {
                score[i] = d1 * 100 + 1000;
            }
            else if(d2 == d3) {
                score[i] = d2 * 100 + 1000;
            }
            else {
                score[i] = d3 * 100 + 1000;
            }
        }
        else {
            score[i] = max(d1, max(d2, d3)) * 100;
        }
    }

    sort(score, score + n);

    printf("%d\n", score[n-1]);
    return 0;
}
