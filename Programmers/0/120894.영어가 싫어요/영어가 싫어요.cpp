#include <bits/stdc++.h>
using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    
    for(int i=0;i<numbers.size();i++) {        
        if(numbers[i] == 'z') {
            answer = answer * 10;
            i += 3;
        }
        else if(numbers[i] == 'o') {
            answer = answer * 10 + 1;
            i += 2;
        }
        else if(numbers[i] == 't') {
            if(numbers[i+1] == 'w') {
                answer = answer * 10 + 2;
                i += 2;
            }
            else {
                answer = answer * 10 + 3;
                i += 4;
            }
        }
        else if(numbers[i] == 'f') {
            if(numbers[i+1] == 'o') {
                answer = answer * 10 + 4;
                i += 3;
            }
            else {
                answer = answer * 10 + 5;
                i += 3;
            }
        }
        else if(numbers[i] == 's') {
            if(numbers[i+1] == 'i') {
                answer = answer * 10 + 6;
                i += 2;
            }
            else {
                answer = answer * 10 + 7;
                i += 4;
            }
        }
        else if(numbers[i] == 'e') {
            answer = answer * 10 + 8;
            i += 4;
        }
        else {
            answer = answer * 10 + 9;
            i += 3;
        }
    }
    
    return answer;
}