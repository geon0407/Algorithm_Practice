#include <stdio.h>
#include <stdlib.h>

int N, X;

int main(void)
{
	int i, number;
	scanf("%d %d", &N, &X);
	
	for(i=0;i<N;i++) {
		scanf("%d", &number);
		if(number < X) {
			printf("%d ", number);
		}
	}
	
	return 0;
}
