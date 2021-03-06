/*************************************************************
 *  > Description      : 计算几何模板
 *  > File Name        : Geometry.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/04/28 19:01:25
 *  > Copyright (C) 2019 Tony_Wong
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10;     //精度
const double PI  = acos(-1);

/**
 * @brief 点(向量)
 * @param x 横坐标
 * @param y 纵坐标
 */
struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};
typedef Point Vector;
Vector operator + (Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator - (Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y); }
Vector operator * (Vector a, double p) { return Vector(a.x * p, a.y * p); }
Vector operator / (Vector a, double p) { return Vector(a.x / p, a.y / p); }
/**
 * @brief 带精度比较(三态函数)
 * @param[in]  x  输入
 * @return 大小关系：等于0(0), 小于零(-1), 大于零(1)
 */
int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

bool operator < (const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool operator == (const Point& a, const Point& b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double Dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double Length(Vector a) { return sqrt(Dot(a, a)); }
double Angle(Vector a, Vector b) { return acos(Dot(a, b) / Length(a) / Length(b)); }
double Cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
double Area2(Point a, Point b, Point c) { return Cross(b - a, c - a); }
double Dist2(const Point& A, const Point& B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }
double angle(Vector v) { return atan2(v.y, v.x); }

/**
 * @brief 向量旋转
 * @param[in]  a    向量
 * @param[in]  rad  旋转角度(逆时针)
 * @return 旋转后的向量
 */
Vector Rotate(Vector a, double rad) {
    return Vector(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad));
}

/**
 * @brief 求单位向量
 * @param[in]  a  向量
 * @return 沿向量a的单位向量
 */
Vector Normal(Vector a) {
    double L = Length(a);
    return Vector(-a.y / L, a.x / L);
}

/**
 * @brief 两条直线交点
 * @param[in]  p  第一条直线的起始点
 * @param[in]  v  第一条直线的方向向量
 * @param[in]  q  第二条直线的起始点
 * @param[in]  w  第二条直线的方向向量
 * @return 两条直线交点
 */
Point GetLineIntersection(Point p, Vector v, Point q, Vector w) {
    Vector u = p - q;
    double t = Cross(w, u) / Cross(v, w);
    return p + v * t;
}

/**
 * @brief 点到直线距离
 * @param[in]  p    点
 * @param[in]  a,b  直线上两点
 * @return 点到直线距离
 */
double DistanceToLine(Point p, Point a, Point b) {
    Vector v1 = b - a, v2 = p - a;
    return fabs(Cross(v1, v2)) / Length(v1);
}

/**
 * @brief 点到线段距离
 * @param[in]  p    点
 * @param[in]  a,b  线段两端点
 * @return 点到线段距离
 */
double DistanceToSegment(Point p, Point a, Point b) {
    if (a == b) return Length(p - a);
    Vector v1 = b - a, v2 = p - a, v3 = p - b;
    if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
    else if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
    else return fabs(Cross(v1, v2)) / Length(v1);
}

/**
 * @brief 点在直线上投影点
 * @param[in]  p    点
 * @param[in]  a,b  直线上两点
 * @return 点在直线上投影点
 */
Point GetLineProjection(Point p, Point a, Point b) {
    Vector v = b - a;
    return a + v * (Dot(v, p - a) / Dot(v, v));
}

/**
 * @brief 线段相交判定(不含端点)
 * @param[in]  a1,a2  第一条线段端点
 * @param[in]  b1,b2  第二条线段端点
 * @return 是否相交(bool)
 */
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
           c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

/**
 * @brief 点在线段上判定(不包括端点)
 * @param[in]  p      点
 * @param[in]  a1,a2  线段两端点
 * @return 是否在线段上(bool)
 */
bool OnSegment(Point p, Point a1, Point a2) {
    return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

/**
 * @brief 多边形面积
 * @param[in]  *p  顶点数组
 * @param[in]
 * @return 
 */
double PolygonArea(Point* p, int n) {
    double area = 0;
    for (int i = 1; i < n - 1; ++i) {
        area += Cross(p[i] - p[0], p[i + 1] - p[0]);
    }
    return area / 2;
}

/**
 * @brief 直线(参数式)
 * @param p   直线上的一点
 * @param v   方向向量
 * @param ang 方向向量极角
 * @function point(double t)
 *     @brief        直线上的点
 *     @param[in] t  横坐标
 *     @return       直线上的点
 * @function move(double d)
 *     @brief        沿直线移动
 *     @param[in] d  平移距离
 *     @return       平移后的直线
 */
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

/**
 * @brief 是否在直线左侧
 * @param[in]  L  直线
 * @param[in]  p  点
 * @return 是否在点左侧(bool)
 */
bool OnLeft(Line L, Point p) {
    return Cross(L.v, p - L.p) > 0;
}

/**
 * @brief 两条直线交点(重载)
 * @param[in]  a  第一条直线
 * @param[in]  b  第二条直线
 * @return 两条直线交点
 */
Point GetLineIntersection(Line a, Line b) {
    Vector u = a.p - b.p;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.p + a.v * t;
}

/**
 * @brief 圆
 * @param c   圆心
 * @param r   半径
 * @function point(double a)
 *     @brief         圆上的点
 *     @param[in]  a  横坐标
 *     @return        圆上的点
 */
struct Circle {
    Point c;
    double r;
    Circle(Point c, double r): c(c), r(r) {}
    Point point(double a) {
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
};

/**
 * @brief 直线和圆交点
 * @param[in]   L      直线
 * @param[in]   C      圆
 * @param[out]  t1,t2  交点横坐标
 * @param[out]  sol    交点集(vector)
 * @return 交点个数
 */
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

/**
 * @brief 圆和圆交点
 * @param[in]   C1,C2  两圆
 * @param[out]  sol    交点集(vector)
 * @return 交点个数
 */
int GetCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol) {
    double d = Length(C1.c - C2.c);
    if (dcmp(d) == 0) {
        if (dcmp(C1.r - C2.r) == 0) return -1;
        return 0;
    }
    if (dcmp(C1.r + C2.r - d) < 0) return 0;
    if (dcmp(fabs(C1.r - C2.r) - d) > 0) return 0;
    double a = angle(C2.c - C1.c);
    double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
    Point p1 = C1.point(a - da), p2 = C1.point(a + da);
    sol.push_back(p1);
    if (p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
}

/**
 * @brief 求切线
 * @param[in]   p   点
 * @param[in]   C   圆
 * @param[out]  *v  切线
 * @return 切线条数
 */
int getTangents(Point p, Circle C, Vector* v) {
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

/**
 * @brief 两圆公切线
 * @param[in]   A,B    两圆
 * @param[out]  *a,*b  切点
 * @return 公切线条数
 */
int getTangents(Circle A, Circle B, Point* a, Point* b) {
    int cnt = 0;
    if (A.r - B.r) { swap(A, B); swap(a, b); }
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

typedef vector<Point> Polygon;
/**
 * @brief 判定点在多边形内
 * @param[in]  p     点
 * @param[in]  poly  多边形
 * @return 是否在多边形内(在1,不在0,在边上-1)
 */
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

/**
 * @brief 凸包
 * @param[in]  p  点集
 * @return 凸包多边形
 */
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

/**
 * @brief 旋转卡壳
 * @param[in]  points  点集
 * @return 直径
 */
int diameter2(vector<Point>& points) { //旋转卡壳
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
                ans = max(ans, (int)Dist2(p[u], p[v]));
                if (diff == 0) ans = max(ans, (int)Dist2(p[u], p[v + 1]));
                break;
            }
            v = (v + 1) % n;
        }
    }
    return ans;
}

/**
 * @brief 切多边形
 * @param[in]  poly  多边形
 * @param[in]  A,B   直线上两点
 * @return 新多边形
 */
Polygon CutPolygon(Polygon poly, Point A, Point B) {
    Polygon newpoly;
    int n = poly.size();
    for (int i = 0; i < n; ++i) {
        Point C = poly[i];
        Point D = poly[(i + 1) % n];
        if (dcmp(Cross(B - A, C - A)) >= 0) newpoly.push_back(C);
        if (dcmp(Cross(B - A, C - D)) != 0) {
            Point ip = GetLineIntersection(A, B - A, C, D - C);
            if (OnSegment(ip, C, D)) newpoly.push_back(ip);
        }
    }
    return newpoly;
}

/**
 * @brief 半平面交
 * @param[in]  L  直线集
 * @return 多边形
 */
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