#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, m5, m25, m125;
    scanf("%d", &n);
    m5 = n / 5;
    m25 = n / 25;
    m125 = n / 125;
    
    printf("%d\n", m5 + m25 + m125);
    return 0;
}
