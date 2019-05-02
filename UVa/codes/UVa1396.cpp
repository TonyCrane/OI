/*************************************************************
 *  > File Name        : UVa1396.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/02 16:55:22
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};
typedef Point Vector;
Vector operator + (Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator - (Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y); }
Vector operator * (Vector a, double p) { return Vector(a.x * p, a.y * p); }
Vector operator / (Vector a, double p) { return Vector(a.x / p, a.y / p); }

double Dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double Length(Vector a) { return sqrt(Dot(a, a)); }
double Cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
Vector Normal(Vector a) { double L = Length(a); return Vector(-a.y / L, a.x / L); }

struct Line {
    Point p;
    Vector v;
    double ang;
    Line() {}
    Line(Point p, Vector v): p(p), v(v) { ang = atan2(v.y, v.x); }
    bool operator < (const Line& L) const {
        return ang < L.ang;
    }
    Point point(double t) {
        return p + v * t;
    }
    Line move(double d) {
        return Line(p + Normal(v) * d, v);
    }
};
bool OnLeft(Line L, Point p) {
    return Cross(L.v, p - L.p) > 0;
}
Point GetLineIntersection(Line a, Line b) {
    Vector u = a.p - b.p;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.p + a.v * t;
}
double PolygonArea(vector<Point> p) {
    int n = p.size();
    double area = 0;
    for (int i = 1; i < n - 1; ++i) {
        area += Cross(p[i] - p[0], p[i + 1] - p[0]);
    }
    return area / 2;
}
vector<Point> HalfplaneIntersection(vector<Line> L) {
    int n = L.size();
    sort(L.begin(), L.end());
    int first, last;
    vector<Point> p(n);
    vector<Line>  q(n);
    vector<Point> ans;
    q[first = last = 0] = L[0];
    for (int i = 1; i < n; i++) {
        while (first < last && !OnLeft(L[i], p[last - 1])) last--;
        while (first < last && !OnLeft(L[i], p[first]))   first++;
        q[++last] = L[i];
        if (fabs(Cross(q[last].v, q[last - 1].v)) < eps) {
            last--;
            if (OnLeft(q[last], L[i].p)) q[last] = L[i];
        }
        if (first < last) p[last - 1] = GetLineIntersection(q[last - 1], q[last]);
    }
    while (first < last && !OnLeft(q[first], p[last - 1])) last--;
    if (last - first <= 1) return ans;
    p[last] = GetLineIntersection(q[last], q[first]);
    for (int i = first; i <= last; i++) ans.push_back(p[i]);
    return ans;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n) {
        vector<Point> p, v, normal;
        int m, x, y;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            p.push_back(Point(x, y));
        }
        if (PolygonArea(p) < 0) reverse(p.begin(), p.end());
        for (int i = 0; i < n; ++i) {
            v.push_back(p[(i + 1) % n] - p[i]);
            normal.push_back(Normal(v[i]));
        }
        double l = 0, r = 20000;
        while (r - l > eps) {
            vector<Line> L;
            double mid = l + (r - l) / 2;
            for (int i = 0; i < n; ++i) {
                L.push_back(Line(p[i] + normal[i] * mid, v[i]));
            }
            vector<Point> poly = HalfplaneIntersection(L);
            if (poly.empty()) {
                r = mid;
            } else {
                l = mid;
            }
        }
        printf("%.6lf\n", l);
    }
    return 0;
}