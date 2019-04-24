/*************************************************************
 *  > File Name        : UVa1308.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/04/23 12:41:47
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const double eps    = 5 * 1e-13;
const double PI     = acos(-1);
const double TWO_PI = PI * 2;
const int    maxn   = 110;

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
double angle(Vector a) { return atan2(a.y, a.x); }
Vector Rotate(Vector a, double rad) {
    return Vector(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad));
}
Vector Normal(Vector a) {
    double L = Length(a);
    return Vector(-a.y / L, a.x / L);
}

void GetCircleCircleIntersection(Point c1, double r1, Point c2, double r2, vector<double>& rad) {
    double d = Length(c1 - c2);
    if (dcmp(d) == 0) return ;
    if (dcmp(r1 + r2 - d) < 0) return ;
    if (dcmp(fabs(r1 - r2) - d) > 0) return ;
    double a  = angle(c2 - c1);
    double da = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    rad.push_back(a - da);
    rad.push_back(a + da);
}

int n;
double rad[maxn];
bool vis[maxn];
Point cen[maxn];

int topmost(Point p) {
    for (int i = n - 1; i >= 0; --i) {
        if (Length(cen[i] - p) < rad[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    while (cin >> n) {
        if (!n) return 0;
        for (int i = 0; i < n; ++i) {
            double x, y, r;
            cin >> x >> y >> r;
            cen[i] = Point(x, y);
            rad[i] = r;
        }
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            vector<double> sec;
            sec.push_back(0);
            sec.push_back(TWO_PI);
            for (int j = 0; j < n; ++j) {
                GetCircleCircleIntersection(cen[i], rad[i], cen[j], rad[j], sec);
            }
            sort(sec.begin(), sec.end());
            for (int j = 0; j < sec.size(); ++j) {
                double mid = (sec[j] + sec[j + 1]) / 2.0;
                for (int side = -1; side <= 1; side += 2) {
                    double r2 = rad[i] - side * eps;
                    int t = topmost(Point(cen[i].x + cos(mid) * r2, cen[i].y + sin(mid) * r2));
                    if (t >= 0) vis[t] = true;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}