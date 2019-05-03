/*************************************************************
 *  > File Name        : P3953.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/03 12:13:43
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int inf  = 0x7fffffff;
const int maxn = 100010;

struct Node {
    int x, y;
    Node(int x, int y): x(x), y(y) {}
};

int n, m, k, p, T;
vector<Node> v[maxn], s[maxn];
int d[maxn], ans[maxn][60];
bool vis[maxn][60], alive[maxn];
queue<int> q, f;

int dfs(int a, int b) { //a当前点,b允许走的冤枉路长度
    if (b < 0) {
        return 0;
    } else if (vis[a][b] == 1) {  //又回来了
        return -inf;              //无穷多种(-inf用于判断)
    } else if (ans[a][b] != -1) { //算过了
        return ans[a][b];
    } else {
        vis[a][b] = true;
        int key = 0;
        if (a == n) { //到目的地
            key++;
        }
        for (int i = 0; i < v[a].size(); ++i) {
            int g = v[a][i].x, y = v[a][i].y; //g本条边终点,y权值
            int u = d[g] - d[a];
            if (alive[g] == 0) { //不能到终点
                continue;
            }
            int w = dfs(g, b - (y - u));
            if (w == -inf) {
                return -inf;
            } else {
                key = (key + w) % p;
            }
        }
        ans[a][b] = key % p;
        vis[a][b] = false; //回溯
        return key;
    }
}

void safe() { //排除无法到终点的点(反向SPFA)
    f.push(n);
    alive[n] = 1;  //点n自身可以到达
    while (!f.empty()) {
        int h = f.front(); f.pop();
        for (int i = 0; i < s[h].size(); ++i) {
            int g = s[h][i].x;
            if (alive[g] == 0) {
                alive[g] = 1;
                f.push(g);
            }
        }
    }
    return ;
}

void spfa() { //SPFA求最短路
    q.push(1);
    d[1] = 0;
    while (!q.empty()) {
        int h = q.front(); q.pop();
        for (int i = 0; i < v[h].size(); ++i) {
            int g = v[h][i].x, y = v[h][i].y;
            if (d[h] + y < d[g]) {
                d[g] = d[h] + y;
                q.push(g);
            }
        }
    }
    return ;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &k, &p);
        for (int i = 1; i <= n; ++i) {
            v[i].clear();
            s[i].clear();
            alive[i] = 0;
            for (int j = 0; j <= k; ++j) {
                ans[i][j] = -1;
                vis[i][j] = 0;
            }
        }
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            v[a].push_back(Node(b, c));     //正向边
            s[b].push_back(Node(a, c));     //反向边
        }
        for (int i = 2; i <= n; ++i) {
            d[i] = inf;
        }
        spfa();  //SPFA求最短路
        safe();
        int z = dfs(1, k);
        if (z == -inf) {
            printf("-1\n");
        } else {
            printf("%d\n", z);
        }
    }
    return 0;
}