/*************************************************************
 *  > File Name        : UVa11168.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/04/25 12:45:01
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

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
double PolygonArea(Polygon p) {
    double area = 0;
    int n = p.size();
    for(int i = 1; i < n-1; i++)
        area += Cross(p[i] - p[0], p[i + 1] - p[0]);
    return area / 2;
}
void toNormal(Point p1, Point p2, double& a, double& b, double& c) {
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = -a * p1.x - b * p1.y;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k) {
        int n;
        scanf("%d", &n);
        vector<Point> p;
        double sumx = 0, sumy = 0;
        for (int i = 0; i < n; ++i) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            p.push_back(Point(x, y));
            sumx += x; sumy += y;
        }
        vector<Point> convex = ConvexHull(p);
        int m = convex.size();
        double ans = 1e9;
        if (m <= 2) ans = 0;
        else for (int i = 0; i < m; ++i) {
            double a, b, c;
            toNormal(convex[i], convex[(i + 1) % m], a, b, c);
            ans = min(ans, fabs(a * sumx + b * sumy + c * n) / (sqrt(a * a + b * b)));
        }
        printf("Case #%d: %.3lf\n", k, ans / n);
    }
    return 0;
}