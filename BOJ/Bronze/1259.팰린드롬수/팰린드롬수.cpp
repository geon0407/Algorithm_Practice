#include <bits/stdc++.h>  
using namespace std;

int main(void)
{
    while( 1 ) {
        string num;
        bool flag = true;
        cin >> num;
        if(num == "0") {
            exit(0);
        }

        for(int i=0;i<num.size()/2;i++) {
            if(num[i] != num[num.size()-i-1]) {
                flag = false;
                break;
            }
        }

        if(flag) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}
