#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> array, int n) {
    vector<pair<int, int>> v;
    
    for(auto i : array) {
        v.push_back(make_pair(abs(i-n), i));
    }
    sort(v.begin(), v.end());
    
    return v[0].second;
}