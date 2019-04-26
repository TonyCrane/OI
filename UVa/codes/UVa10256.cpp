/*************************************************************
 *  > File Name        : UVa10256.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/04/25 13:05:34
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};
typedef Point Vector;
typedef vector<Point> Polygon;
Vector operator + (Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator - (Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y); }
Vector operator * (Vector a, double p) { return Vector(a.x * p, a.y * p); }
Vector operator / (Vector a, double p) { return Vector(a.x / p, a.y / p); }
bool operator < (const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool operator == (const Point& a, const Point& b) {
    return a.x == b.x && a.y == b.y;
}
int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
double Dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double Cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
Polygon ConvexHull(vector<Point> p) {
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size();
    int m = 0;
    Polygon ch(n + 1);
    for (int i = 0; i < n; ++i) {
        while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; --i) {
        while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if (n > 1) m--;
    ch.resize(m);
    return ch;
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
           c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
bool OnSegment(Point p, Point a1, Point a2) {
    return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}
int isPointInPolygon(Point p, Polygon poly) {
    int wn = 0;
    int n = poly.size();
    for (int i = 0; i < n; ++i) {
        if (OnSegment(p, poly[i], poly[(i + 1) % n])) return -1;
        int k = dcmp(Cross(poly[(i + 1) % n] - poly[i], p - poly[i]));
        int d1 = dcmp(poly[i].y - p.y);
        int d2 = dcmp(poly[(i + 1) % n].y - p.y);
        if (k > 0 && d1 <= 0 && d2 > 0) wn++;
        if (k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if (wn != 0) return 1;
    return 0;
}

bool judge(vector<Point> p1, vector<Point> p2) {
    int n1 = p1.size(), n2 = p2.size();
    for (int i = 0; i < n1; ++i) {
        if (isPointInPolygon(p1[i], p2)) {
            return false;
        }
    }
    for (int i = 0; i < n2; ++i) {
        if (isPointInPolygon(p2[i], p1)) {
            return false;
        }
    }
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            if (SegmentProperIntersection(p1[i], p1[(i + 1) % n1], p2[j], p2[(j + 1) % n2])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2 && n > 0 && m > 0) {
        vector<Point> p1, p2;
        double x, y;
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf", &x, &y);
            p1.push_back(Point(x, y));
        }
        for (int i = 0; i < m; ++i) {
            scanf("%lf %lf", &x, &y);
            p2.push_back(Point(x, y));
        }
        if (judge(ConvexHull(p1), ConvexHull(p2))) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}