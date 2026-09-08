#include <bits/stdc++.h> 
using namespace std;

priority_queue<int, vector<int>, greater<int>> q1;
priority_queue<int, vector<int>> q2;

int main(void)
{
    int n, x;
    scanf("%d", &n);

    while(n--) {
        scanf("%d", &x);

        if(!x) {
            if(q1.empty() && q2.empty()) {
                printf("0\n");
            }
            else {
                if(q1.empty()) {
                    printf("%d\n", q2.top());
                    q2.pop();
                }
                else if(q2.empty()) {
                    printf("%d\n", q1.top());
                    q1.pop();
                }
                else {
                    if(q1.top() < -q2.top()) {
                        printf("%d\n", q1.top());
                        q1.pop();
                    }
                    else {
                        printf("%d\n", q2.top());
                        q2.pop();
                    }
                }
            }
        }
        else if(x > 0) {
            q1.push(x);
        }
        else {
            q2.push(x);
        }
    }

    return 0;
}
