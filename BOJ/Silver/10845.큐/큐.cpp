#include <bits/stdc++.h>
using namespace std;

queue<int> data;

int main(void)
{
    int n, i;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        char com[10];
        scanf("%s", com);
        if(strcmp(com, "push") == 0) {
            int in;
            scanf("%d", &in);
            data.push(in);
        }
        else if(strcmp(com, "pop") == 0) {
            if(data.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", data.front());
                data.pop();
            }
        }
        else if(strcmp(com, "size") == 0) {
            printf("%d\n", data.size());
        }
        else if(strcmp(com, "empty") == 0) {
            printf("%d\n", data.empty());
        }
        else if(strcmp(com, "front") == 0) {
            if(data.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", data.front());
            }
        }
        else {
            if(data.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", data.back());
            }
        }
    }

    return 0;
}
