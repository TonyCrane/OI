/*************************************************************
 *  > File Name        : P2761.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/15 09:13:33
 *  > Algorithm        : 状压+最短路
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

inline int read_() {
    char ch = getchar();
    while (ch != '+' && ch != '-' && ch != '0') ch = getchar();
    if (ch == '+') return 1;
    else if (ch == '-') return 2;
    return 0;
}

const int inf = 0x3f3f3f3f;

struct DLL {
    int time;
    int b1, b2;
    int f1, f2;
}node[110];

int n, m, s, t;
int dis[1 << 21];
bool vis[1 << 21];

void SPFA(int s) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0; vis[s] = true;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (int i = 1; i <= m; ++i) {
            if ((u & node[i].b1) == node[i].b1 && (u & node[i].b2) == 0) {
                int v = ((u | node[i].f1) | node[i].f2) ^ node[i].f1;
                if (dis[v] > dis[u] + node[i].time) {
                    dis[v] = dis[u] + node[i].time;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }
}

int main() {
    n = read(); m = read();
    s = (1 << n) - 1; t = 0;
    for (int i = 1; i <= m; ++i) {
        node[i].time = read();
        for (int j = 0; j < n; ++j) {
            int sta = read_();
            if (sta == 1) node[i].b1 |= (1 << j);
            if (sta == 2) node[i].b2 |= (1 << j);
        }
        for (int j = 0; j < n; ++j) {
            int sta = read_();
            if (sta == 2) node[i].f1 |= (1 << j);
            if (sta == 1) node[i].f2 |= (1 << j);
        }
    }
    SPFA(s);
    printf("%d\n", dis[t] == inf ? 0 : dis[t]);
    return 0;
}