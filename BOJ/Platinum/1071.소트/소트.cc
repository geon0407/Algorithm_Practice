#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

int main(void)
{
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int in;
        scanf("%d", &in);
        v.push_back(in);
    }
    sort(v.begin(), v.end());

    int cnt=0;
    for(int i=0;i<v.size()-1;i++) {
        if(v[i]+1 == v[i+1]) {  //인접한 두 숫자가 연속된 경우
            vector<int>::iterator it = lower_bound(v.begin()+i, v.end(), v[i]+2); //처음으로 연속되지 않는 곳 찾기
            if(it != v.end()) {
                swap(*it, v[i+1]);
            }
            else {
                vector<int>::iterator u = upper_bound(v.begin()+i+1, v.end(), v[i]);
                vector<int>::iterator l = lower_bound(v.begin()+i-cnt, v.end(), v[i]);
                while(u != v.end()) {
                    swap(*u, *l);
                    l++;
                    u++;
                }
            }
            cnt = 0;
        }
        else if(v[i+1] == v[i]) { //같은 숫자 묶음인 경우
            cnt++;
        }
    }

    for(auto i : v) {
        printf("%d ", i);
    }

    return 0;
}