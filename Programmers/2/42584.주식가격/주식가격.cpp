#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> st;

    st.push(0);
    for(int i=1;i<prices.size();i++) {
        while(!st.empty() && prices[i] < prices[st.top()]) {
            int idx = st.top();
            st.pop();
            answer[idx] = i - idx;
        }

        st.push(i);
    }

    while(!st.empty()) {
        int idx = st.top();
        st.pop();
        answer[idx] = prices.size() - idx - 1;
    }

    return answer;
}