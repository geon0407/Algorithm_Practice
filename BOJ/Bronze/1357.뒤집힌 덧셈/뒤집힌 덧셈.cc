#include <bits/stdc++.h>
using namespace std;

string n1, n2;
int n;

int main(void)
{
    cin >> n1 >> n2;
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    n = atoi(n1.c_str()) + atoi(n2.c_str());

    if(n == 0) {
        printf("0");
        exit(0);
    }

    while(n % 10 == 0) {
        n /= 10;
    }

    while(n != 0) {
        printf("%d", n%10);
        n /= 10;
    }

    return 0;
}