#include <bits/stdc++.h>
using namespace std;

using pnt = pair<int, int>;
using lin = pair<pair<int, int>, pair<int, int>>;

int solution(vector<int> arrows) {
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int answer = 0;

    pnt p = make_pair(0, 0);
    set<pnt> pchk;
    set<lin> lchk;

    pchk.insert(p);
    for(auto a : arrows) {
        for(int i=0;i<2;i++) {
            pnt np = make_pair(p.first + dx[a], p.second + dy[a]);

            auto tmp1 = pchk.insert(np);
            auto tmp2 = lchk.insert(make_pair(max(p, np), min(p, np)));
            if(!tmp1.second && tmp2.second) {
                answer++;
            }

            p = np;
        }
    }

    return answer;
}
