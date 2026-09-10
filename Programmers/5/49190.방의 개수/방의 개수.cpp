#include <bits/stdc++.h>
using namespace std;

using pnt = pair<int, int>;
using lin = pair<pair<int, int>, pair<int, int>>;

int solution(vector<int> arrows) {
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int answer = 0;

    int x=0, y=0;
    set<pnt> pchk;
    set<lin> lchk;

    pchk.insert(make_pair(0, 0));
    for(auto a : arrows) {
        for(int i=0;i<2;i++) {
            int nx, ny;
            nx = x + dx[a];
            ny = y + dy[a];

            auto tmp1 = pchk.insert(make_pair(nx, ny));
            auto tmp2 = lchk.insert(make_pair(max(make_pair(x, y) ,make_pair(nx, ny)), min(make_pair(x, y) ,make_pair(nx, ny))));
            if(!tmp1.second && tmp2.second) {
                answer++;
            }

            x = nx;
            y = ny;
        }
    }

    return answer;
}
