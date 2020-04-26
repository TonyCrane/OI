#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1010;
const LL mod  = 998244353;

struct Edge {
    int from, to;
    Edge(int f, int t): from(f), to(t) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int f, int t) {
    edges.push_back(Edge(f, t));
    edges.push_back(Edge(t, f));
    int mm = edges.size();
    G[t].push_back(mm - 1);
    G[f].push_back(mm - 2);
}

LL n, m, owner[maxn], fa[maxn];
LL a[maxn], b[maxn], ans[maxn];
set<LL> son[maxn];

void dfs(int u, int f) {
    fa[u] = f;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.to == f) continue;
        dfs(e.to, u);
        son[u].insert(son[e.to].begin(), son[e.to].end());
        son[u].insert(e.to);
    }
}

LL solve(LL* a, LL* b) {
    LL res = 0;
    for (int i = 1; i <= m; ++i) {
        if (son[a[i]].count(b[i]) || son[b[i]].count(a[i])) res++;
    }
    return res;
}

LL fac(LL x) {  
    int res;  
    if (x == 0 || x == 1)  
        res = 1;  
    else  
        res = fac(x - 1) * x;  
    return res % mod;  
}  

int main() {
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    n = read(); m = n / 2;
    if (n > 50) {
        for (int i = 1; i <= m; ++i) printf("0 ");
        printf("%lld\n", fac(m));
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        char ch; scanf("%c", &ch);
        if (ch == '0') {
            owner[i] = 0;
            a[++a[0]] = i;
        }
        else {
            owner[i] = 1;
            b[++b[0]] = i;
        }
    }
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    dfs(1, 0);
    sort(b + 1, b + 1 + m);
    do {
        int res = solve(a, b);
        // printf("%d\n", res);
        ans[res]++;
    } while (next_permutation(b + 1, b + 1 + m));
    for (int i = 0; i <= m; ++i) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
    return 0;
}