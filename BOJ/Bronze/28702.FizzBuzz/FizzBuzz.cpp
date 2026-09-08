#include <bits/stdc++.h>
using namespace std;

string ans(int n)
{
    if(n % 3 == 0 && n % 5 == 0) {
        return "FizzBuzz";
    }
    else if(n % 3 == 0) {
        return "Fizz";
    }
    else if(n % 5 == 0) {
        return "Buzz";
    }

    return to_string(n);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    if(0 < s3[0] - '0' && s3[0] - '0' <= 9) {
        cout << ans(stoi(s3) + 1);
        exit(0);
    }
    if(0 < s2[0] - '0' && s2[0] - '0' <= 9) {
        cout << ans(stoi(s2) + 2);
        exit(0);
    }
    if(0 < s1[0] - '0' && s1[0] - '0' <= 9) {
        cout << ans(stoi(s1) + 3);
        exit(0);
    }

    return 0;
}
