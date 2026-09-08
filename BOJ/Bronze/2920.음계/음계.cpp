#include <stdio.h> 
#include <stdlib.h> 
#include <algorithm>

using namespace std;

int main(void)
{
    int i, index=0, in, flag=0;
    scanf("%d", &in);
    if(in == 1) {
        index = 2;
        flag = 1;
        for(i=0;i<7;i++) {
            scanf("%d", &in);
            if(in != index) {
                printf("mixed\n");
                exit(0);
            }
            index += flag;
        }
        printf("ascending\n");
        exit(0);
    }
    else if(in == 8) {
        index = 7;
        flag = -1;
        for(i=0;i<7;i++) {
            scanf("%d", &in);
            if(in != index) {
                printf("mixed\n");
                exit(0);
            }
            index += flag;
        }
        printf("descending\n");
        exit(0);
    }
    else {
        printf("mixed\n");
        exit(0);
    }
    return 0;
}
