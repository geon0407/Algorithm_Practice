#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int sum = sequence[0], st = 0, fi = 0;

    answer[1] = numeric_limits<int>::max();
    while(fi < sequence.size()) {
        if(sum < k) {
            sum += sequence[++fi];
        }
        else if(sum > k) {
            sum -= sequence[st++];
        }
        else {
            if(answer[1] - answer[0] > fi - st) {
                answer[0] = st;
                answer[1] = fi;
            }
            
            sum += sequence[++fi];
        }
    }

    return answer;
}
