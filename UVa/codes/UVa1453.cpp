/*************************************************************
 *  > File Name        : UVa1453.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/04/26 12:59:58
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0): x(x), y(y) {}
};
typedef Point Vector;
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
int Dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
int Cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
int Dist2(const Point& A, const Point& B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }

vector<Point> ConvexHull(vector<Point> p) {
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size();
    int m = 0;
    vector<Point> ch(n + 1);
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

int diameter2(vector<Point>& points) {
    vector<Point> p = ConvexHull(points);
    int n = p.size();
    if (n == 1) return 0;
    if (n == 2) return Dist2(p[0], p[1]);
    p.push_back(p[0]);
    int ans = 0;
    for (int u = 0, v = 1; u < n; ++u) {
        for(;;) {
            int diff = Cross(p[u + 1] - p[u], p[v + 1] - p[v]);
            if (diff <= 0) {
                ans = max(ans, Dist2(p[u], p[v]));
                if (diff == 0) ans = max(ans, Dist2(p[u], p[v + 1]));
                break;
            }
            v = (v + 1) % n;
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<Point> p;
        for (int i = 0; i < n; ++i) {
            int x, y, w;
            scanf("%d %d %d", &x, &y, &w);
            p.push_back(Point(x    , y    ));
            p.push_back(Point(x + w, y    ));
            p.push_back(Point(x    , y + w));
            p.push_back(Point(x + w, y + w));
        }
        printf("%d\n", diameter2(p));
    }
    return 0;
}