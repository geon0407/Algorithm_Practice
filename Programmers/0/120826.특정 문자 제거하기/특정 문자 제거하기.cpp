#include <bits/stdc++.h>
using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    
    for(auto i : my_string) {
        if(letter[0] != i) {
            answer += i;
        }
    }
    
    return answer;
}