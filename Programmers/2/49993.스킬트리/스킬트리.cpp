#include <bits/stdc++.h>
using namespace std;

int chk(string skill, string tree) {
    int cur = 0;
    
    for(auto &c : tree) {
        for(int i=0;i<skill.length();i++) {
            if(c == skill[i]) {
                if(i-cur) {
                    return 0;
                }
                else {
                    cur++;
                }
            }
        }
    }
    
    return 1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(auto &s : skill_trees) {
        answer += chk(skill, s);
    }

    return answer;
}