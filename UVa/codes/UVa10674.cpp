/*************************************************************
 *  > File Name        : UVa10674.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/04/21 21:52:59
**************************************************************/

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const double eps = 1e-8;
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
int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
bool operator < (const Point& a, const Point& b) {
    return dcmp(a.x - b.x) < 0 || (dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) < 0);
}
bool operator == (const Point& a, const Point& b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double Dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double Length(Vector a) { return sqrt(Dot(a, a)); }
double angle(Vector v) {
    return atan2(v.y, v.x);
}
struct Circle {
    Point c;
    double r;
    Circle(Point c, double r): c(c), r(r) {}
    Point point(double a) {
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
};

int getTangents(Circle A, Circle B, Point* a, Point* b) {
    int cnt = 0;
    if (A.r < B.r) { swap(A, B); swap(a, b); }
    int d2 = (A.c.x - B.c.x) * (A.c.x - B.c.x) + (A.c.y - B.c.y) * (A.c.y - B.c.y);
    int rdiff = A.r - B.r;
    int rsum  = A.r + B.r;
    if (d2 < rdiff * rdiff) return 0;
    double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
    if (d2 == 0 && A.r == B.r) return -1;
    if (d2 == rdiff * rdiff) {
        a[cnt] = A.point(base);
        b[cnt] = B.point(base);
        cnt++;
        return 1;
    }
    double ang = acos((A.r - B.r) / sqrt(d2));
    a[cnt] = A.point(base + ang); b[cnt] = B.point(base + ang); cnt++;
    a[cnt] = A.point(base - ang); b[cnt] = B.point(base - ang); cnt++;
    if (d2 == rsum * rsum) {
        a[cnt] = A.point(base);
        b[cnt] = B.point(PI + base);
        cnt++;
    } else if (d2 > rsum * rsum) {
        double ang = acos((A.r + B.r) / sqrt(d2));
        a[cnt] = A.point(base + ang); b[cnt] = B.point(PI + base + ang); cnt++;
        a[cnt] = A.point(base - ang); b[cnt] = B.point(PI + base - ang); cnt++;
    }
    return cnt;
}

int x1, Y1, r1, x2, y2, r2;

int main() {
    while (scanf("%d %d %d %d %d %d", &x1, &Y1, &r1, &x2, &y2, &r2) == 6 && r1) {
        Point a[4], b[4];
        int n = getTangents(Circle(Point(x1, Y1), r1), Circle(Point(x2, y2), r2), a, b);
        printf("%d\n", n);
        if (n > 0) {
            int p[4] = {0, 1, 2, 3};
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (a[p[j]] < a[p[i]] || (a[p[i]] == a[p[j]] && b[p[j]] < b[p[i]])) {
                        swap(p[i], p[j]);
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                printf("%.5lf %.5lf %.5lf %.5lf %.5lf\n", a[p[i]].x, a[p[i]].y, b[p[i]].x, b[p[i]].y, Length(a[p[i]] - b[p[i]]));
            }
        }
    }
    return 0;
}