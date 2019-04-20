#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10;

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
Vector Normal(Vector a) {
    double L = Length(a);
    return Vector(-a.y / L, a.x / L);
}
Point GetLineIntersection(Point p, Vector v, Point q, Vector w) {
    Vector u = p - q;
    double t = Cross(w, u) / Cross(v, w);
    return p + v * t;
}
double DistanceToLine(Point p, Point a, Point b) {
    Vector v1 = b - a, v2 = p - a;
    return fabs(Cross(v1, v2)) / Length(v1);
}
double DistanceToSegment(Point p, Point a, Point b) {
    if (a == b) return Length(p - a);
    Vector v1 = b - a, v2 = p - a, v3 = p - b;
    if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
    else if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
    else return fabs(Cross(v1, v2)) / Length(v1);
}
Point GetLineProjection(Point p, Point a, Point b) {
    Vector v = b - a;
    return a + v * (Dot(v, p - a) / Dot(v, v));
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
           c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
bool OnSegment(Point p, Point a1, Point a2) {
    return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}
double ConvexPolygonArea(Point* p, int n) {
    double area = 0;
    for (int i = 1; i < n - 1; ++i) {
        area += Cross(p[i] - p[0], p[i + 1] - p[0]);
    }
    return area / 2;
}
double PolygonArea(Point* p, int n) {
    double area = 0;
    for (int i = 1; i < n - 1; ++i) {
        area += Cross(p[i] - p[0], p[i + 1] - p[0]);
    }
    return area / 2;
}
struct Line {
    Point p;
    Vector v;
    Line(Point p, Vector v): p(p), v(v) {}
    Point point(double t) {
        return p + v * t;
    }
    Line move(double d) {
        return Line(p + Normal(v) * d, v);
    }
};
struct Circle {
    Point c;
    double r;
    Circle(Point c, double r): c(c), r(r) {}
    Point point(double a) {
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
};


int main() {
    return 0;
}