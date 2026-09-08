#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    stack<int> st;
    string command;
    int i, n;
    cin >> n;

    for(i=0;i<n;i++) {
        cin >> command;

        if(command == "push") {
            int num;
            cin >> num;
            st.push(num);
        }
        else if(command == "pop") {
            if(!st.empty()) {
                cout << st.top() << endl;
                st.pop();
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(command == "size") {
            cout << st.size() << endl;
        }
        else if(command == "empty") {
            if(st.empty()) {
                cout << "1" << endl;
            }
            else {
                cout << "0" << endl;
            }
        }
        else if(command == "top") {
            if(!st.empty()) {
                cout << st.top() << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
    }

    return 0;
}
