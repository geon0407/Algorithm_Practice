#include <bits/stdc++.h>
using namespace std;

vector<int> number;

int main(void)
{
    int i, n, cnt=0;
    scanf("%d", &n);
    while(n != 0) {
        number.push_back(n % 10);
        n /= 10;
        cnt++;
    }
    sort(number.begin(), number.end());
    reverse(number.begin(), number.end());
    for(i=0;i<cnt;i++) {
        printf("%d", number[i]);
    }
    printf("\n");
    return 0;
}
