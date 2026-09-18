#include <bits/stdc++.h>
using namespace std;

using psi = pair<string, int>;

vector<psi> dict[1010];
int dict_size = 0;

int find(string s) {
    int cur = s.size();

    for(auto i : dict[cur]) {
        if(s == i.first) {
            return i.second;
        }
    }

    return 0;
}

vector<int> solution(string msg) {
    vector<int> answer;

    for(char c='A';c<='Z';c++) {
        string tmp = "";
        tmp += c;
        dict[1].push_back(make_pair(tmp, ++dict_size));
    }

    while(!msg.empty()) {
        string cpy = msg, backup = "";
        int loc = find(cpy);

        while(!loc) {
            backup = cpy;
            cpy.pop_back();
            loc = find(cpy);
        }

        msg.erase(0, cpy.size());
        dict[backup.size()].push_back(make_pair(backup, ++dict_size));
        answer.push_back(loc);
    }

    return answer;
}