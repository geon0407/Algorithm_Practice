#include <bits/stdc++.h> 
using namespace std;

bool d[21] = {false};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int m;
    cin >> m;

    while(m--) {
        string cmd;
        int x;
        cin >> cmd;

        if(cmd == "add") {
            cin >> x;
            d[x] = true;
        }
        else if(cmd == "remove") {
            cin >> x;
            d[x] = false;
        }
        else if(cmd == "check") {
            cin >> x;
            cout << d[x] << "\n";
        }
        else if(cmd == "toggle") {
            cin >> x;
            d[x] = !d[x];
        }
        else if(cmd == "all") {
            for(int i=1;i<=20;i++) {
                d[i] = true;
            }
        }
        else {
            for(int i=1;i<=20;i++) {
                d[i] = false;
            }
        }
    }

    return 0;
}
