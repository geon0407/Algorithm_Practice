#include <bits/stdc++.h>
using namespace std;

int solution(string before, string after)
{
    for(auto c : before) {
        bool flag = true;

        for(auto &k : after) {
            if(c == k) {
                k = '0';
                flag = false;
                break;
            }
        }

        if(flag) {
            return 0;
        }
    }

    return 1;
}