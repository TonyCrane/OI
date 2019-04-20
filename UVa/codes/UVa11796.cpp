/*************************************************************
 *  > File Name        : UVa11796.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/04/20 17:16:30
**************************************************************/

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

Point read_point() {
    double x, y;
    scanf("%lf %lf", &x, &y);
    return Point(x, y);
}

const int maxn = 60;
const double inf = 1e9;

int T, A, B, kase = 1;
Point P[maxn], Q[maxn];
double minn, maxx;

void update(Point p, Point a, Point b) {
    minn = min(minn, DistanceToSegment(p, a, b));
    maxx = max(maxx, Length(p - a));
    maxx = max(maxx, Length(p - b));
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &A, &B);
        for (int i = 0; i < A; ++i) {
            P[i] = read_point();
        }
        for (int i = 0; i < B; ++i) {
            Q[i] = read_point();
        }
        double LenA = 0, LenB = 0;
        for (int i = 0; i < A - 1; ++i) {
            LenA += Length(P[i + 1] - P[i]);
        }
        for (int i = 0; i < B - 1; ++i) {
            LenB += Length(Q[i + 1] - Q[i]);
        }
        int Sa = 0, Sb = 0;
        Point Pa = P[0], Pb = Q[0];
        minn = inf; maxx = -inf;
        while (Sa < A - 1 && Sb < B - 1) {
            double La = Length(P[Sa + 1] - Pa);
            double Lb = Length(Q[Sb + 1] - Pb);
            double t = min(La / LenA, Lb / LenB);
            Vector Va = (P[Sa + 1] - Pa) / La * t * LenA;
            Vector Vb = (Q[Sb + 1] - Pb) / Lb * t * LenB;
            update(Pa, Pb, Pb + Vb - Va);
            Pa = Pa + Va;
            Pb = Pb + Vb;
            if (Pa == P[Sa + 1]) Sa++;
            if (Pb == Q[Sb + 1]) Sb++;
        }
        printf("Case %d: %.0lf\n", kase++, maxx - minn);
    }
}