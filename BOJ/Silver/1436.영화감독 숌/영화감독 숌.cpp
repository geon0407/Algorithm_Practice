#include <bits/stdc++.h> 
using namespace std; 

int f(int n);

int main(void)
{
    int t, num=665;
    scanf("%d", &t);

    while(t) {
        t -= f(++num);
    }

    printf("%d\n", num);
    return 0;
}

int f(int n)
{
    vector<int> v;

    while(n) {
        v.push_back(n%10);
        n /= 10;
    }

    for(int i=0;i<v.size()-2;i++) {
        if(v[i] == 6 && v[i+1] == 6 && v[i+2] == 6) {
            return 1;
        }
    }

    return 0;
}
