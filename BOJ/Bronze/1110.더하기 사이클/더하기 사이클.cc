#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number, ten, one, temp, cnt=0;
    scanf("%d", &number);

    ten = number / 10;
    one = number % 10;

    while( 1 ) {
        cnt++;
        temp = ten;
        ten = one;
        one = (temp + one) % 10;
        if((ten*10) + one == number)
            break;
    }
    printf("%d\n", cnt);
}
