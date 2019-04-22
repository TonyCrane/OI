/*************************************************************
 *  > File Name        : UVa12304.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/04/21 22:22:17
**************************************************************/

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

const double eps = 1e-6;
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
Vector Normal(Vector a) {
    double L = Length(a);
    return Vector(-a.y / L, a.x / L);
}
Point GetLineIntersection(Point p, Vector v, Point q, Vector w) {
    Vector u = p - q;
    double t = Cross(w, u) / Cross(v, w);
    return p + v * t;
}
double angle(Vector v) {
    return atan2(v.y, v.x);
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
Line GetLine(double x1, double Y1, double x2, double y2) {
    Point p1(x1, Y1);
    Point p2(x2, y2);
    return Line(p1, p2 - p1);
}
struct Circle {
    Point c;
    double r;
    Circle(Point c, double r): c(c), r(r) {}
    Point point(double a) {
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
};
Point GetLineIntersection(Line a, Line b) {
  return GetLineIntersection(a.p, a.v, b.p, b.v);
}
int GetLineCircleIntersection(Line L, Circle C, double& t1, double& t2, vector<Point>& sol) {
    double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
    double e = a * a + c * c, f = 2 * (a * b + c * d), g = b * b + d * d - C.r * C.r;
    double delta = f * f - 4 * e * g;
    if (dcmp(delta) < 0 ) return 0;
    if (dcmp(delta) == 0) {
        t1 = t2 = -f / (2 * e);
        sol.push_back(L.point(t1));
        return 1;
    }
    t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(L.point(t1));
    t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(L.point(t2));
    return 2;
}
int GetCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol) {
    double d = Length(C1.c - C2.c);
    if (dcmp(d) == 0) {
        if (dcmp(C1.r - C2.r) == 0) return -1;
        return 0;
    }
    if (dcmp(C1.r + C2.r - d) < 0) return 0;
    if (dcmp(fabs(C1.r - C2.r) - d) < 0) return 0;
    double a = angle(C2.c - C1.c);
    double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
    Point p1 = C1.point(a - da), p2 = C1.point(a + da);
    sol.push_back(p1);
    if (p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
}

/*** Solve ***/
// Problem 1
Circle CircumscribedCircle(Point p1, Point p2, Point p3) {
    double Bx = p2.x - p1.x, By = p2.y - p1.y;
    double Cx = p3.x - p1.x, Cy = p3.y - p1.y;
    double D = 2 * (Bx * Cy - By * Cx);
    double cx = (Cy * (Bx * Bx + By * By) - By * (Cx * Cx + Cy * Cy)) / D + p1.x;
    double cy = (Bx * (Cx * Cx + Cy * Cy) - Cy * (Bx * Bx + By * By)) / D + p1.y;
    Point p = Point(cx, cy);
    return Circle(p, Length(p1 - p));
}

// Problem 2
Circle InscribedCircle(Point p1, Point p2, Point p3) {
    double a = Length(p2 - p3);
    double b = Length(p3 - p1);
    double c = Length(p1 - p2);
    Point p = (p1 * a + p2 * b + p3 * c) / (a + b + c);
    return Circle(p, DistanceToLine(p, p1, p2));
}

// Problem 3
int TangentLineThroughPoint(Point p, Circle C, Vector* v) {
    Vector u = C.c - p;
    double dist = Length(u);
    if (dist < C.r) return 0;
    else if (dcmp(dist - C.r) == 0) {
        v[0] = Rotate(u, PI / 2);
        return 1;
    } else {
        double ang = asin(C.r / dist);
        v[0] = Rotate(u, -ang);
        v[1] = Rotate(u, +ang);
        return 2;
    }
}
double LineAngleDegree(Vector v) {
    double ang = angle(v) * 180.0 / PI;
    while (dcmp(ang) < 0) ang += 360.0;
    while (dcmp(ang - 180) >= 0) ang -= 180.0;
    return ang;
}

// Problem 4
vector<Point> CircleThroughPointTangentToLineGivenRadius(Point p, Line L, double r) {
    vector<Point> ans;
    double t1, t2;
    GetLineCircleIntersection(L.move(-r), Circle(p, r), t1, t2, ans);
    GetLineCircleIntersection(L.move(r) , Circle(p, r), t1, t2, ans);
    return ans;
}

// Problem 5
vector<Point> CircleTangentToLinesGivenRadius(Line a, Line b, double r) {
    vector<Point> ans;
    Line L1 = a.move(-r), L2 = a.move(r);
    Line L3 = b.move(-r), L4 = b.move(r);
    ans.push_back(GetLineIntersection(L1, L3));
    ans.push_back(GetLineIntersection(L1, L4));
    ans.push_back(GetLineIntersection(L2, L3));
    ans.push_back(GetLineIntersection(L2, L4));
    return ans;
}

// Problem 6
vector<Point> CircleTangentToTwoDisjointCirclesWithRadius(Circle c1, Circle c2, double r) {
    vector<Point> ans;
    Vector v = c2.c - c1.c;
    double dist = Length(v);
    int d = dcmp(dist - c1.r - c2.r - r * 2);
    if (d > 0) return ans;
    GetCircleCircleIntersection(Circle(c1.c, c1.r + r), Circle(c2.c, c2.r + r), ans);
    return ans;
}

/*** Output ***/
// Problem 1 2
void print(Circle c) {
    printf("(%.6lf,%.6lf,%.6lf)\n", c.c.x, c.c.y, c.r);
}

// Problem 3
void print(const vector<double>& ans) {
    int n = ans.size();
    sort(ans.begin(), ans.end());
    printf("[");
    if (n) {
        printf("%.6lf", ans[0]);
        for (int i = 1; i < n; ++i) {
            printf(",%.6lf", ans[i]);
        }
    }
    printf("]\n");
}

// Problem 4 5 6
void print(const vector<Point>& ans) {
    int n = ans.size();
    sort(ans.begin(), ans.end());
    printf("[");
    if (n) {
        printf("(%.6lf,%.6lf)", ans[0].x, ans[0].y);
        for (int i = 1; i < n; ++i) {
            printf(",(%.6lf,%.6lf)", ans[i].x, ans[i].y);
        }
    }
    printf("]\n");
}

/*** main ***/
double x1, Y1, x2, y2, x3, y3, x4, y4, xp, yp, xc, yc, r1, r2, r;

int main() {
    string opt;
    while (cin >> opt) {
        if (opt == "CircumscribedCircle") {
            cin >> x1 >> Y1 >> x2 >> y2 >> x3 >> y3;
            print(CircumscribedCircle(Point(x1, Y1), Point(x2, y2), Point(x3, y3)));
        }
        if (opt == "InscribedCircle") {
            cin >> x1 >> Y1 >> x2 >> y2 >> x3 >> y3;
            print(InscribedCircle(Point(x1, Y1), Point(x2, y2), Point(x3, y3)));
        }
        if (opt == "TangentLineThroughPoint") {
            cin >> xc >> yc >> r >> xp >> yp;
            Vector v[2];
            vector<double> ans;
            int cnt = TangentLineThroughPoint(Point(xp, yp), Circle(Point(xc, yc), r), v);
            for (int i = 0; i < cnt; i++) ans.push_back(LineAngleDegree(v[i]));
            print(ans);
        }
        if (opt == "CircleThroughAPointAndTangentToALineWithRadius") {
            cin >> xp >> yp >> x1 >> Y1 >> x2 >> y2 >> r;
            print(CircleThroughPointTangentToLineGivenRadius(Point(xp, yp), GetLine(x1, Y1, x2, y2), r));
        }
        if (opt == "CircleTangentToTwoLinesWithRadius") {
            cin >> x1 >> Y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> r;
            print(CircleTangentToLinesGivenRadius(GetLine(x1, Y1, x2, y2), GetLine(x3, y3, x4, y4), r));
        }
        if (opt == "CircleTangentToTwoDisjointCirclesWithRadius") {
            cin >> x1 >> Y1 >> r1 >> x2 >> y2 >> r2 >> r;
            print(CircleTangentToTwoDisjointCirclesWithRadius(Circle(Point(x1, Y1), r1), Circle(Point(x2, y2), r2), r));
        }
    }
}