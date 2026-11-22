#include <stdio.h>
#include <stdlib.h>

char s[100];
int NUM[100];
int N;

void func(int, char, int);

int main(void)
{
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf(" %c", &s[i]);
    }

    func(9, '>', -1);

    printf("\n");
    func(0, '<', 1);

    return 0;
}

void func(int start, char chr, int dir)
{
    int i, j, length, num;
    num = start; 
    for(i = 0 ; i <= N ; i++)
    {
        for(j = i ; j < N ; j++) 
            if(s[j] == chr)
                break;
        length = j - i; 
        for(j = i + length ; j >= i ; j--)
        {
            NUM[j] = num; 
            num += dir; 
        }
        i += length; 
    }

    for(i = 0 ; i <= N ; i++) 
    {
        printf("%d", NUM[i]);
    }
}
