/*************************************************************
 *  > File Name        : P2278.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/26 15:59:39
 *  > Algorithm        : [DataStructure]priority_queue
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int Time;

struct Node {
    int id, st, dt, p;
    bool operator < (const Node& a) const {
        if (p == a.p) return st > a.st;
        else return p < a.p;
    }
}in;

int main() {
    priority_queue<Node> q;
    while (scanf("%d %d %d %d", &in.id, &in.st, &in.dt, &in.p)!= EOF) {
        while (!q.empty() && Time + q.top().dt <= in.st) {
            Node out = q.top(); q.pop(); Time += out.dt;
            printf("%d %d\n", out.id, Time);
        }
        if (!q.empty()) {
            Node top = q.top(); q.pop();
            top.dt = top.dt - in.st + Time;
            q.push(top);
        }
        q.push(in);
        Time = in.st;
    }
    while (!q.empty()) {
        Node out = q.top(); q.pop();
        Time += out.dt;
        printf("%d %d\n", out.id, Time);
    }
    return 0;
}