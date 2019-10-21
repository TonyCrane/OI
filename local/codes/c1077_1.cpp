/*************************************************************
 *  > File Name        : c1077_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/18 13:04:12
 *  > Algorithm        : 并查集 100 Points
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 10010;
const int maxm = 1000010;

int n, m;
stack<pair<int, int> > edges;
int ufs[maxn * 2];

int find(int x) {
    return ufs[x] == x ? x : find(ufs[x]);
}

void unionn(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) {
        edges.push(pair<int, int>(-1, 0));
        return;
    }
    ufs[fx] = fy;
    edges.push(pair<int, int>(fx, fy));
}

void del() {
    if (edges.top().first == -1) {
        edges.pop();
        return;
    }
    int x = edges.top().first;
    int y = edges.top().second;
    ufs[x] = x;
    edges.pop();
}

bool query(int x, int y) {
    return find(x) == find(y);
}

bool valid[maxm];
int front[maxm], last;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= 2 * n; ++i) {
        ufs[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int opt = read();
        if (opt == 1) {
            int x = read(), y = read();
            front[i] = last;
            if (valid[last]) valid[i] = 1;
            else if (query(x, y) || query(x + n, y + n)) {
                valid[i] = 1;
            } else {
                unionn(x, y + n);
                unionn(x + n, y);
            }
            last = i;
            printf(valid[i] ? "NO\n" : "YES\n");
        } else {
            if (!valid[last]) {
                del(); del();
            }
            last = front[last];
            printf(valid[last] ? "NO\n" : "YES\n");
        }
    }
    return 0;
}