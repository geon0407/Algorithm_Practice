#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    stack<int> st;
    int k;
    scanf("%d", &k);

    for(int i=0;i<k;i++) {
        int in;
        scanf("%d", &in);

        if(in) {
            st.push(in);
        }
        else {
            st.pop();
        }
    }

    int ans = 0;
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    printf("%d\n", ans);
    return 0;
}
