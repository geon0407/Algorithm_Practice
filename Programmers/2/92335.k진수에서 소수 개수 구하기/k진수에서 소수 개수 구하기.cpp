#include <bits/stdc++.h>
using namespace std;

int isPrime(long long n) {
    if(n < 2) {
        return 0;
    }

    for(long long i=2;i<=sqrt(n);i++) {
        if(n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int solution(int n, int k) {
    string number = "";
    int answer = 0;

    while( n ) {
        number += to_string(n % k);
        n /= k;
    }
    reverse(number.begin(), number.end());

    long long tmp = 0;
    for(auto c : number) {
        if(c == '0') {
            answer += isPrime(tmp);
            tmp = 0;
        }
        else {
            tmp *= 10;
            tmp += c - '0';
        }
    }

    return answer + isPrime(tmp);
}