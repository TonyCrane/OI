/*************************************************************
 *  > File Name        : P2571.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/07 15:13:40
 *  > Algorithm        : 三分
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};
Point operator + (Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator - (Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator * (Point a, double p) { return Point(a.x * p, a.y * p); }
Point operator / (Point a, double p) { return Point(a.x / p, a.y / p); }
double dist(const Point& A, const Point& B) { return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)); }

Point A, B, C, D;
double P, Q, R;

double calc(Point X) {
    Point l = C, r = D;
    while (dist(l, r) > eps) {
        Point lmid = l + (r - l) / 3;
        Point rmid = r - (r - l) / 3;
        double lans = dist(lmid, D) / Q + dist(X, lmid) / R;
        double rans = dist(rmid, D) / Q + dist(X, rmid) / R;
        if (rans - lans > eps) r = rmid;
        else l = lmid;
    }
    return dist(l, D) / Q + dist(X, l) / R;
}

int main() {
    scanf("%lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y);
    scanf("%lf %lf %lf %lf", &C.x, &C.y, &D.x, &D.y);
    scanf("%lf %lf %lf", &P, &Q, &R);
    Point l = A, r = B;
    while (dist(l, r) > eps) {
        Point lmid = l + (r - l) / 3;
        Point rmid = r - (r - l) / 3;
        double lans = calc(lmid) + dist(lmid, A) / P;
        double rans = calc(rmid) + dist(rmid, A) / P;
        if (rans - lans > eps) r = rmid;
        else l = lmid;
    }
    printf("%.2lf\n", calc(l) + dist(l, A) / P);
    return 0;
}