#include <bits/stdc++.h>
using namespace std;

stack< pair<int, int> > st;
int n, k;

int main(void)
{
    int i;
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        scanf("%d", &k);
        while(!st.empty()) {
            if(st.top().second > k) {
                printf("%d ", st.top().first);
                break;
            }
            st.pop();
        }
        if(st.empty()) {
            printf("0 ");
        }
        st.push(make_pair(i, k));
    }
    return 0;
}