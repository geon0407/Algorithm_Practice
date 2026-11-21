#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int f(int i);

int Cup, Wine[10010], Record[10010];

int main(void)
{
    int i;
    scanf("%d", &Cup);
    for(i=1;i<=Cup;i++) {
        scanf("%d", &Wine[i]);
    }

    for(i=0;i<=Cup;i++) {
        Record[i] = f(i);
    }

    printf("%d\n", Record[Cup]);
    return 0;
}

int f(int i)
{
    if(i == 0) {
        return 0;
    }
    else if(i == 1) {
        return Wine[1];
    }
    else if(i == 2) {
        return Wine[1] + Wine[2];
    }
    return max(Record[i-3] + Wine[i-1] + Wine[i], max(Record[i-1], Record[i-2] + Wine[i]));
}
