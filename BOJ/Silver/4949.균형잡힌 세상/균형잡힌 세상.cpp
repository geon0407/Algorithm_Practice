#include <bits/stdc++.h>
using namespace std;

string f(string s);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    while( 1 ) {
        string in;
        getline(cin, in);

        if(in == ".") {
            exit(0);
        }

        cout << f(in) << "\n";
    }

    return 0;
}

string f(string s)
{
    stack<char> st;
    for(auto c : s) {
        if(c == '(' || c == '[') {
            st.push(c);
        }
        if(c == ')') {
            if(st.empty() || st.top() != '(') {
                return "no";
            }
            st.pop();
        }
        if(c == ']') {
            if(st.empty() || st.top() != '[') {
                return "no";
            }
            st.pop();
        }
    }
    
    if(!st.empty()) {
        return "no";
    }

    return "yes";
}
