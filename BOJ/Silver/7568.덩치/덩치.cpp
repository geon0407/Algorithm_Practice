#include <stdio.h>
#include <stdlib.h>

struct data {
    int kg;
    int cm;
    int grade = 1;
};

int n, i, j;

int main(void)
{
    data person[100];
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        scanf("%d %d", &person[i].kg, &person[i].cm);
    }

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(person[i].cm < person[j].cm && person[i].kg < person[j].kg) {
                person[i].grade++;
            }
        }
    }

    for(i=0;i<n;i++) {
        printf("%d ", person[i].grade);
    }

    return 0;
}
