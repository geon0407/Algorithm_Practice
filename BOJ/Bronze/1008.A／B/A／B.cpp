#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double num1, num2;

    scanf("%lf %lf", &num1, &num2);
    printf("%.9lf\n", num1 / num2);

    return 0;
}
