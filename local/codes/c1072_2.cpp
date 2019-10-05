/*************************************************************
 *  > File Name        : c1072_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/05 12:52:45
 *  > Algorithm        : dfs
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 12;
const int maxans = 310;
const int go[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int n, a[maxn][maxn], nowans[maxn][maxn];
bool vis[maxn][maxn], visx[maxn][maxn], visy[maxn][maxn];

struct Node {
    int x, y;
};
struct AnsMat {
    int mat[maxn][maxn];
    bool operator < (const AnsMat& a) const {
        for (int i = 1; i < 11; ++i)
            for (int j = 1; j < 11; ++j)
                if (mat[i][j] != a.mat[i][j])
                    return mat[i][j] < a.mat[i][j];
        return false;
    }
}ans[maxans]; int ans_cnt;
vector<Node> color[maxn * maxn]; int color_cnt;
vector<int> factor[maxn * maxn];
bool cmp(vector<Node> a, vector<Node> b) {
    if (a.size() != b.size()) return a.size() < b.size();
    int resa = 0, resb = 0;
    for (int i = 1; i * i <= a[0].x; ++i)
        if (a[0].x % i == 0)
            resa++;
    for (int i = 1; i * i <= b[0].x; ++i)
        if (b[0].x % i == 0)
            resb++;
    return resa <= resb;
}

bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n && !vis[x][y];
}
void dfs1(int x, int y) {
    vis[x][y] = true;
    color[color_cnt].push_back((Node){x, y});
    for (int i = 0; i < 4; ++i) {
        int x2 = x + go[i][0];
        int y2 = y + go[i][1];
        if (valid(x2, y2) && a[x][y] == a[x2][y2]) {
            dfs1(x2, y2);
        }
    }
}

void dfs3(int, int, int, int);

void dfs2(int col) {
    if (col > color_cnt) {
        ans_cnt++;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                ans[ans_cnt].mat[i][j] = nowans[i][j];
            }
        }
    } else {
        dfs3(col, 1, color[col][0].x, color[col].size() - 1);
    }
}

void dfs3(int col, int dep, int num, int cnt) {
    if (dep > cnt) {
        dfs2(col + 1);
    } else {
        int nx = color[col][dep].x;
        int ny = color[col][dep].y;
        for (int i = 0; i < factor[col].size(); ++i) {
            int p = factor[col][i];
            if ((num == p || dep < cnt) && num % p == 0 \
                && !visx[nx][p] && !visy[ny][p]) {
                visx[nx][p] = true; visy[ny][p] = true;
                nowans[nx][ny] = p;
                dfs3(col, dep + 1, num / p, cnt);
                nowans[nx][ny] = 0;
                visx[nx][p] = false; visy[ny][p] = false;
            }
        }
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = read();
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!vis[i][j]) {
                color[++color_cnt].push_back((Node){a[i][j], 0});
                dfs1(i, j);
            }
        }
    }
    sort(color + 1, color + 1 + color_cnt, cmp);
    for (int i = 1; i <= color_cnt; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (color[i][0].x % j == 0) {
                factor[i].push_back(j);
            }
        }
    }
    dfs2(1);
    printf("%d\n", ans_cnt);
    AnsMat Ans = ans[1];
    for (int i = 2; i <= ans_cnt; ++i) {
        Ans = min(Ans, ans[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", Ans.mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}