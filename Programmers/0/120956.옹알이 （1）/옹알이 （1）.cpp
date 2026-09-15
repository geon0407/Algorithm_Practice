#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;
 
    for(string str : babbling) {
        string tmp;
        while(tmp.size() < str.size()) {
            if(str[tmp.size()] == 'a') {
                tmp += "aya";
            }
            else if(str[tmp.size()] == 'y') {
                tmp += "ye";
            }
            else if(str[tmp.size()] == 'w') {
                tmp += "woo";
            }
            else if(str[tmp.size()] == 'm') {
                tmp += "ma";
            }
            else {
                break;
            }
        }

        if(str == tmp) {
            answer++;
        }
    }

    return answer;
}