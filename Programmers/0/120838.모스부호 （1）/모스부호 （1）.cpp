#include <bits/stdc++.h>
using namespace std;

string chk(string str)
{
    string res = "";
    vector<string> moss = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    for(int i=0;i<moss.size();i++) {
        if(moss[i] == str) {
            res.push_back('a'+i);
            return res;
        }
    }
}

string solution(string letter) 
{
    string answer = "";
    string tmp;
    
    for(auto c : letter) {
        if(c == ' ') {
            answer += chk(tmp);
            tmp.clear();
        }
        else {
            tmp += c;
        }
    }
    answer += chk(tmp);
    
    return answer;
}