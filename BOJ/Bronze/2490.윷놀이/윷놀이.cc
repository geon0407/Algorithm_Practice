#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, stick, cnt=0;

	for(i=0;i<3;i++) {
		for(j=0;j<4;j++) {
			scanf("%d", &stick);
			if(stick == 0)
				cnt++;
		}
		if(cnt == 0) {
            printf("E\n");
		}
		else if(cnt == 1) {
            printf("A\n");
		}
		else if(cnt == 2) {
            printf("B\n");
		}
		else if(cnt == 3) {
            printf("C\n");
		}
		else {
            printf("D\n");
		}
		cnt = 0;
	}

	return 0;
}
