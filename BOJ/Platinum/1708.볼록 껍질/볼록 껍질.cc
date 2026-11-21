#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

double ccw(pair<double, double> a, pair<double, double> b, pair<double, double> c);
double dis(pair<double, double> a, pair<double, double> b);

bool cmp(pair<double, double> a, pair<double, double> b);

vector<pair<double, double>> hull;
vector<pair<double, double>> v;
pair<double, double> tmp;

int main(void)
{
    int n, i;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        double a, b;
        scanf("%lf %lf", &a, &b);
        v.push_back(pair<double, double>(a, b));
    }

    sort(v.begin(), v.end());
    tmp = v[0];
    hull.push_back(tmp);
    sort(v.begin()+1, v.end(), cmp);
    for(i=1;i<v.size();i++) {
        int s = hull.size();
        while(s >= 2 && ccw(hull[s-2], hull[s-1], v[i]) <= 0) {
            hull.pop_back();
            s = hull.size();
        }
        hull.push_back(v[i]);
    }

    printf("%d\n", hull.size());
    return 0;
}

double ccw(pair<double, double> a, pair<double, double> b, pair<double, double> c)
{
    double res = 0;
    res += a.x * (b.y - c.y);
    res += b.x * (c.y - a.y);
    res += c.x * (a.y - b.y);

    return res;
}

double dis(pair<double, double> a, pair<double, double> b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return dx*dx + dy*dy;
}

bool cmp(pair<double, double> a, pair<double, double> b)
{
    if(ccw(a, b, tmp) == 0) {
        return dis(a, tmp) < dis(b, tmp);
    }

    return ccw(tmp, a, b) > 0;
}
