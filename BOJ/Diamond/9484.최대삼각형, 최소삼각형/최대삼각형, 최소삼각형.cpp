#include <bits/stdc++.h> 
using namespace std;

struct Point {
    int x, y, idx;

    bool same(Point p)
    {
        return x == p.x && y == p.y;
    }
};

struct Line {
    Point **p1, **p2;
    double slope;

    bool isContain(Point p)
    {
        return (**p1).same(p) || (**p2).same(p);
    }
};

bool cmp_point(Point &p1, Point &p2);
bool cmp_line(Line &l1, Line &l2);
double ccw(Point a, Point b, Point c);

vector<Point> points;
vector<Point*> pt;
vector<Line> lines;
vector<int> arr;

int main(void)
{
    int i, j, k, n;

    while( 1 ) {
        scanf("%d", &n);
        if(!n) {
            exit(0);
        }

        points.resize(n);
        pt.resize(n);
        arr.resize(n);
        for(i=0;i<n;i++) {
            scanf("%d%d", &points[i].x, &points[i].y);
        }
        sort(points.begin(), points.end(), cmp_point);
        for(i=0;i<n;i++) {
            points[i].idx = i;
            pt[i] = &points[i];
            arr[i] = i;
        }

        k=0;
        lines.resize(n*(n-1)/2);
        for(i=0;i<n;i++) {
            for(j=i+1;j<n;j++) {
                lines[k].p1 = &pt[i];
                lines[k].p2 = &pt[j];
                lines[k].slope = atan2(points[j].x-points[i].x, points[j].y-points[i].y);
                k++;
            }
        }
        sort(lines.begin(), lines.end(), cmp_line);

        double small = numeric_limits<double>::max();
        double big = 0.0;
        for(i=0;i<lines.size();i++) {
            Line l = lines[i];
            int p1x, p1y, p2x, p2y;
            p1x = (**l.p1).x;
            p1y = (**l.p1).y;
            p2x = (**l.p2).x;
            p2y = (**l.p2).y;

            if(!l.isContain(points[n-1])) {
                big = max(big, ccw(**l.p1, **l.p2, points[n-1]));
            }
            if(!l.isContain(points[0])) {
                big = max(big, ccw(**l.p1, **l.p2, points[0]));
            }

            int idx1 = (**l.p1).idx;
            int idx2 = (**l.p2).idx;
            if(idx1 > 0 && !l.isContain(points[idx1-1])) {
                small = min(small, ccw(**l.p1, **l.p2, points[idx1-1]));
            }
            if(idx1 < n-1 && !l.isContain(points[idx1+1])) {
                small = min(small, ccw(**l.p1, **l.p2, points[idx1+1]));
            }
            if(idx2 > 0 && !l.isContain(points[idx2-1])) {
                small = min(small, ccw(**l.p1, **l.p2, points[idx2-1]));
            }
            if(idx2 < n-1 && !l.isContain(points[idx2+1])) {
                small = min(small, ccw(**l.p1, **l.p2, points[idx2+1]));
            }

            points[idx1].x = p2x;
            points[idx1].y = p2y;
            points[idx2].x = p1x;
            points[idx2].y = p1y;

            swap(pt[arr[idx1]], pt[arr[idx2]]);
            swap(arr[idx1], arr[idx2]);
        }

        printf("%.1f %.1f\n", small, big);
    }

    return 0;
}

bool cmp_point(Point &p1, Point &p2)
{
    if(p1.x < p2.x) {
        return true;
    }
    else if(p1.x == p2.x) {
        return p1.y < p2.y;
    }
    return false;
}

bool cmp_line(Line &l1, Line &l2)
{
    if(l1.slope < l2.slope) {
        return true;
    }
    else if(l1.slope == l2.slope) {
        if((**l1.p1).idx < (**l2.p1).idx) {
            return true;
        }
        else if((**l1.p1).idx == (**l2.p1).idx) {
            return (**l1.p2).idx < (**l2.p2).idx;
        }
    }
    return false;
}

double ccw(Point a, Point b, Point c)
{
    double res = a.x*b.y + b.x*c.y + c.x*a.y;
    res -= (a.y*b.x + b.y*c.x + c.y*a.x);

    return abs(res) / 2;
}
