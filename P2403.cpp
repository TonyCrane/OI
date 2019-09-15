/*************************************************************
 *  > File Name        : P2403.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/15 17:27:31
 *  > Algorithm        : Tarjan-SCC
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

struct Edge {
    int from, to;
    Edge(int u, int v): from(u), to(v) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v) {
    edges.push_back(Edge(u, v));
    int mm = edges.size();
    G[u].push_back(mm - 1);
}

int n, r, c;

struct Block {
    int x, y, opt, id;
    Block(int x, int y, int o, int i): x(x), y(y), opt(o), id(i) {}
}in[maxn];
map<pair<int, int>, int> id
bool firstx(Block a, Block b) { //先横天门
    if (a.x != b.x) return a.x < b.x;
    if (a.opt == 1) return true;
    if (b.opt == 1) return false;
    return a.y < b.y;
}
bool firsty(Block a, Block b) { //先纵寰门
    if (a.y != b.y) return a.y < b.y;
    if (a.opt == 2) return true;
    if (b.opt == 2) return false;
    return a.x < b.x;
}

void makeGraph() {
    sort(in + 1, in + n + 1, firstx);
    int first = 1, last = 1;
    for (int i = 1; i <= n; ++i) {
        if (in[i].x != in[i + 1].x) {
            if (first != last) {
                add(in[last].id, in[first].id);
            }
            last = first = i + 1;
        } else {
            if (in[last].opt == 1) {
                add(in[last].id, in[i + 1].id);
            }
            if (in[i + 1].opt == 1) {
                last = i + 1;
            }
            if (in[first].opt != 1) {
                last = first = i + 1;
            }
        }
    }
}

int main() {
    n = read(); r = read(); c = read();
    for (int i = 1; i <= n; ++i) {
        in[i].x = read();
        in[i].y = read();
        in[i].opt = read();
        in[i].id = i;
        id[pair<int, int>(in[i].x, in[i].y)] = i;
    }
    makeGraph();
}