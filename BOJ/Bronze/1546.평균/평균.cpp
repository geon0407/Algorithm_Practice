#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

double score[1010];

int main(void)
{
    double av=0, max_score=0;
    int n, i;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%lf", &score[i]);
        max_score = max(max_score, score[i]);
    }

    for(i=0;i<n;i++) {
        score[i] = score[i] / max_score * 100;
        av += score[i];
    }

    printf("%.2lf\n", av / n);
    return 0;
}
