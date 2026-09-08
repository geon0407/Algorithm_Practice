#include <bits/stdc++.h>
using namespace std;

stack<int> s;
vector<char> ans;
int n;

int main(void)
{   
    scanf("%d", &n);
    
    int num = 1;
    for(int i=0;i<n;i++) {
        int in;
        scanf("%d", &in);
        
        if(in >= num) {
            while(in >= num) {
                s.push(num++);
                ans.push_back('+');
            }
            s.pop();
            ans.push_back('-');
        }
        else {
            int tmp = s.top();
            s.pop();
            
            if(tmp > in) {
                printf("NO\n");
                exit(0);
            }
            else {
                ans.push_back('-');
            }
        }
    }
    
    for(auto &c : ans) {
        printf("%c\n", c);
    }
    return 0;
}
