#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int x, y, w, h;
    scanf("%d%d%d%d", &x, &y, &w, &h);
    printf("%d\n", min(h-y, min(y, min(x, w-x))));
    return 0;
}
