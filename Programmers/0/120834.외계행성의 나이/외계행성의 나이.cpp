#include <bits/stdc++.h>
using namespace std;

string solution(int age) {
    string answer = "";

    while(age) {
        answer.push_back((char)(age%10+(int)'a'));
        age /= 10;
    }
    reverse(answer.begin(), answer.end());

    return answer;
}