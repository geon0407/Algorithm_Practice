#include <bits/stdc++.h> 
using namespace std;

void push(long n);
long pop();

vector<long> v;

int main(void)
{
    int n;
    scanf("%d", &n);
    while(n--) {
        long in;
        scanf("%ld", &in);

        if(in) {
            push(in);
        }
        else {
            printf("%ld\n", pop());
        }
    }
}

void push(long n)
{
    v.push_back(n);

    int idx = v.size()-1;
    while(v[idx] > v[(idx-1)/2]) {
        swap(v[idx], v[(idx-1)/2]);
        idx = (idx-1)/2;
    }

    return ;
}

long pop()
{
    if(v.size() == 0) {
        return 0;
    }

    int tmp = v[0];
    v[0] = v[v.size()-1];
    v.pop_back();

    int idx = 0, last = v.size()-1;
    while( 1 ) {
        int left = idx*2+1, right = idx*2+2;
        if(left > last) {
            break;
        }

        int maxV = v[left], maxIdx = left;
        if(right <= last && v[right] > maxV) {
            maxV = v[right];
            maxIdx = right;
        }

        if(maxV > v[idx]) {
            swap(v[idx], v[maxIdx]);
            idx = maxIdx;
        }
        else {
            break;
        }
    }

    return tmp;
}
