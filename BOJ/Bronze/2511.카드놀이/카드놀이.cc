#include <stdio.h>
#include <stdlib.h>

int A[15];
int B[15];

int main(void)
{
    int i, a, b, flag=-1;
    a = b = 0;

    for(i=1;i<=10;i++) {
        scanf("%d", &A[i]);
    }
    for(i=1;i<=10;i++) {
        scanf("%d", &B[i]);
    }

    for(i=1;i<=10;i++) {
        if(A[i] > B[i]) {
            a+=3;
            flag = 0;
        }
        else if(A[i] < B[i]) {
            b+=3;
            flag = 1;
        }
        else {
            a+=1;
            b+=1;
        }
    }

    printf("%d %d\n", a, b);

    if(a > b) {
        printf("A\n");
    }
    else if(a < b) {
        printf("B\n");
    }
    else if(a == b && a == 10) {
        printf("D\n");
    }
    else {
        printf("%c\n", 'A' + flag);
    }

    return 0;
}
