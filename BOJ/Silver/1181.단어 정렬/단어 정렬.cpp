#include <bits/stdc++.h> 
using namespace std; 

bool cmp(const string &str1, const string &str2)
{
    if(str1.size() == str2.size()) {
        return str1 < str2;
    }
    return str1.size() < str2.size();
}

vector<string> v;
int n;

int main(void)
{
    int i;
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);

    vector<string>::iterator it, fi;
    fi = unique(v.begin(), v.end());

    for(it=v.begin();it!=fi;it++) {
        cout << *it << endl;
    }

    return 0;
}
