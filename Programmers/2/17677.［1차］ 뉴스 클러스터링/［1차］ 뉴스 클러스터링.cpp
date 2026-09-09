#include <bits/stdc++.h>
using namespace std;

bool isApb(char c);
string Cap(string s);

int solution(string str1, string str2) {
    double answer = 0;

    vector<string> s1, s2;
    for(int i=0;i<str1.length()-1;i++) {
        string tmp = str1.substr(i, 2);
        tmp = Cap(tmp);

        if(tmp != "00") {
            s1.push_back(tmp);
        }
    }
    for(int i=0;i<str2.length()-1;i++) {
        string tmp = str2.substr(i, 2);
        tmp = Cap(tmp);

        if(tmp != "00") {
            s2.push_back(tmp);
        }
    }

    set<string> isChk;
    int sum = 0;

    for(auto s : s1) {
        auto it = isChk.insert(s);
        if(!it.second) {
            continue;
        }

        int a=0, b=0;
        for(auto tmp : s1) {
            if(tmp == s) {
                a++;
            }
        }
        for(auto tmp : s2) {
            if(tmp == s) {
                b++;
            }
        }

        sum += max(a, b);
    }

    for(auto s : s2) {
        auto it = isChk.insert(s);
        if(!it.second) {
            continue;
        }

        int a=0, b=0;
        for(auto tmp : s1) {
            if(tmp == s) {
                a++;
            }
        }
        for(auto tmp : s2) {
            if(tmp == s) {
                b++;
            }
        }

        sum += max(a, b);
    }

    isChk.clear();
    int inter = 0;

    for(auto s : s1) {
        auto it = isChk.insert(s);
        if(!it.second) {
            continue;
        }

        int a=0, b=0;
        for(auto tmp : s1) {
            if(tmp == s) {
                a++;
            }
        }
        for(auto tmp : s2) {
            if(tmp == s) {
                b++;
            }
        }

        inter += min(a, b);
    }
    
    if(!sum) {
        return 65536;
    }
    answer = (double)inter / (double)sum * 65536;
    return int(answer);
}

string Cap(string s)
{
    if(isApb(s[0]) * isApb(s[1]) == 0) {
        return "00";
    }

    if('a' <= s[0] && s[0] <= 'z') {
        s[0] = 'A' + (s[0] - 'a');
    }
    if('a' <= s[1] && s[1] <= 'z') {
        s[1] = 'A' + (s[1] - 'a');
    }

    return s;
}

bool isApb(char c)
{
    if('a' <= c && c <= 'z') {
        return true;
    }
    if('A' <= c && c <= 'Z') {
        return true;
    }

    return false;
}
