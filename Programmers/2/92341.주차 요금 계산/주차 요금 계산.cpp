#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int calc(vector<int> fees, int t) {
    return ((max(t-fees[0], 0) + fees[2] - 1) / fees[2]) * fees[3] + fees[1];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, pii> park;
    vector<int> answer, cost(10010);

    for(auto i : records) {
        istringstream iss(i);

        string number, mv;
        char col;
        int h, m;

        iss >> h >> col >> m >> number >> mv;

        if(mv == "IN") {
            park.insert({number, make_pair(h, m)});
        }
        else {
            pii out = park[number];
            cost[stoi(number)] += (60*h + m) - (60*out.first + out.second);
            park.erase(number);
        }
    }

    for(auto [number, out] : park) {
        cost[stoi(number)] += (60*23 + 59) - (60*out.first + out.second);
    }

    for(auto i : cost) {
        if(i) {
            answer.push_back(calc(fees, i));
        }
    }

    return answer;
}