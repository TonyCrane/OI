/*************************************************************
 *  > File Name        : UVa10652.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/04/24 14:54:17
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10;
const double PI  = acos(-1);

struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};
typedef Point Vector;
Vector operator + (Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator - (Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y); }
Vector operator * (Vector a, double p) { return Vector(a.x * p, a.y * p); }
Vector operator / (Vector a, double p) { return Vector(a.x / p, a.y / p); }
bool operator < (const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
bool operator == (const Point& a, const Point& b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double Dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double Length(Vector a) { return sqrt(Dot(a, a)); }
double Angle(Vector a, Vector b) { return acos(Dot(a, b) / Length(a) / Length(b)); }
double Cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
double Area2(Point a, Point b, Point c) { return Cross(b - a, c - a); }
Vector Rotate(Vector a, double rad) {
    return Vector(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad));
}

typedef vector<Point> Polygon;

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
double PolygonArea(Polygon p) {
    double area = 0;
    int n = p.size();
    for(int i = 1; i < n-1; i++)
        area += Cross(p[i] - p[0], p[i + 1] - p[0]);
    return area / 2;
}
double torad(double deg) {
    return deg / 180 * PI;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        double area1 = 0;
        scanf("%d", &n);
        vector<Point> p;
        for (int i = 0; i < n; ++i) {
            double x, y, w, h, deg, ang;
            scanf("%lf %lf %lf %lf %lf", &x, &y, &w, &h, &deg);
            Point o(x, y);
            ang = -torad(deg);
            p.push_back(o + Rotate(Vector(- w / 2, - h / 2), ang));
            p.push_back(o + Rotate(Vector(  w / 2, - h / 2), ang));
            p.push_back(o + Rotate(Vector(- w / 2,   h / 2), ang));
            p.push_back(o + Rotate(Vector(  w / 2,   h / 2), ang));
            area1 += w * h;
        }
        double area2 = PolygonArea(ConvexHull(p));
        printf("%.1lf %%\n", area1 * 100 / area2);
    }
    return 0;
}