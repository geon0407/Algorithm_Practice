#include <bits/stdc++.h> 
using namespace std;

void push(int n);
int pop();

vector<int> v;

int main(void)
{
    int n;
    scanf("%d", &n);
    while(n--) {
        int in;
        scanf("%d", &in);

        if(in) {
            push(in);
        }
        else {
            printf("%d\n", pop());
        }
    }
}

void push(int n)
{
    v.push_back(n);

    int idx = v.size()-1;
    while(v[idx] < v[(idx-1)/2]) {
        swap(v[idx], v[(idx-1)/2]);
        idx = (idx-1)/2;
    }

    return ;
}

int pop()
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

        int minV = v[left], minIdx = left;
        if(right <= last && v[right] < minV) {
            minV = v[right];
            minIdx = right;
        }

        if(minV < v[idx]) {
            swap(v[idx], v[minIdx]);
            idx = minIdx;
        }
        else {
            break;
        }
    }

    return tmp;
}
