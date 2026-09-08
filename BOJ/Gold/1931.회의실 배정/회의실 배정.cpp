#include <bits/stdc++.h> 
using namespace std;

struct Data {
    int start;
    int finish;
};

bool cmp_data(Data a, Data b)
{
    if(a.finish == b.finish) {
        return a.start < b.start;
    }
    return a.finish < b.finish;
}

Data meet[100010];

int main(void)
{
    int N, i, index, res;
    scanf("%d", &N);

    for(i=0;i<N;i++) {
        scanf("%d %d", &meet[i].start, &meet[i].finish);
    }

    sort(meet, meet+N, cmp_data);

    index = 0;
    res = 0;
    for(i=0;i<N;i++) {
        if(meet[i].start >= index) {
            res++;
            index = meet[i].finish;
        }
    }

    printf("%d\n", res);
    return 0;
}
