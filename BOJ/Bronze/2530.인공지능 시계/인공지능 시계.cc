#include <stdio.h>
#include <stdlib.h>

int hour, minute, second, need_time;

int main(void)
{
    int i;
    scanf("%d %d %d %d", &hour, &minute, &second, &need_time);

    for(i=1;i<=need_time;i++) {
        second++;
        if(second == 60) {
            second = 0;
            minute++;
        }
        if(minute == 60) {
            second = minute = 0;
            hour++;
        }
        if(hour == 24) {
            second = minute = hour = 0;
        }
    }

    printf("%d %d %d", hour, minute, second);
    return 0;
}
