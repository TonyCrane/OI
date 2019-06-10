/*************************************************************
 *  > Description      : 数据结构模板
 *  > File Name        : DataStructure.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/29 12:11:37
 *  > Copyright (C) 2019 Tony
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}
const int maxn = 10010;
const int inf  = 0x3f3f3f3f;

/**
 * @brief 可撤销并查集
 */
struct UnionFindSet {
    int ufs[maxn];
    inline void sroot(int u) {
        for (int i = 0, fa = ufs[u]; u; fa = ufs[u]) {
            ufs[u] = i; i = u; u = fa;
        }
    }
    void connect(int u, int v) {
        ufs[u] = v;
    }
    void del(int u, int v) {
        ufs[v] = 0;
    }
    void query(int u, int v) {
        for (; v != u && v; v = ufs[v]);
        puts(v == u ? "Yes" : "No");
    }
};

/**
 * @brief 树状数组
 */
struct BIT {
    int bit[maxn], n, m;
    int lowbit(int k) { return k & -k; }
    void add(int x, int k) {
        while (x <= maxn) {
            bit[x] += k;
            x += lowbit(x);
        }
    }
    int sum(int x) {
        int ans = 0;
        while (x != 0) {
            ans += bit[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

/**
 * @brief 线段树
 */
struct SegmentTree {
    struct SegmentTreeNode {
        int l, r;
        long long sum, add;
        #define l(x) tree[x].l
        #define r(x) tree[x].r
        #define sum(x) tree[x].sum
        #define add(x) tree[x].add
    } tree[maxn * 4];
    int a[maxn], n, m;
    void build(int p, int l, int r) {
        l(p) = l, r(p) = r;
        if (l == r) { sum(p) = a[l]; return; }
        int mid = (l + r) >> 1;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
        sum(p) = sum(p * 2) + sum(p * 2 + 1);
    }
    void pushdown(int p) {
        if (add(p)) {
            sum(p * 2) += add(p) * (r(p * 2) - l(p * 2) + 1);
            sum(p * 2 + 1) += add(p) * (r(p * 2 + 1) - l(p * 2 + 1) + 1);
            add(p * 2) += add(p);
            add(p * 2 + 1) += add(p);
            add(p) = 0;
        }
    }
    void update(int p, int l, int r, int d) {
        if (l <= l(p) && r >= r(p)) {
            sum(p) += (long long)d * (r(p) - l(p) + 1);
            add(p) += d;
            return;
        }
        pushdown(p);
        int mid = (l(p) + r(p)) >> 1;
        if (l <= mid) update(p * 2, l, r, d);
        if (r >  mid) update(p * 2 + 1, l, r, d);
        sum(p) = sum(p * 2) + sum(p * 2 + 1);
    }
    long long query(int p, int l, int r) {
        if (l <= l(p) && r >= r(p)) return sum(p);
        pushdown(p);
        int mid = (l(p) + r(p)) >> 1;
        long long ans = 0;
        if (l <= mid) ans += query(p * 2, l, r);
        if (r >  mid) ans += query(p * 2 + 1, l, r);
        return ans;
    }
    #undef add
    #undef sum
    #undef l
    #undef r
};

/**
 * @brief 分块
 */
struct Block {
    LL a[maxn], sum[maxn], add[maxn];
    int L[maxn], R[maxn];
    int pos[maxn];
    int n, m, t;
    void change(int l, int r, LL d) {
    	int p = pos[l], q = pos[r];
    	if (p == q) {
    		for (int i = l; i <= r; ++i) a[i] += d;
    		sum[p] += d * (r - l + 1);
    	} else {
    		for (int i = p + 1; i <= q - 1; ++i) add[i] += d;
    		for (int i = l; i <= R[p]; ++i) a[i] += d;
    		sum[p] += d * (R[p] - l + 1);
    		for (int i = L[q]; i <= r; ++i) a[i] += d;
    		sum[q] += d * (r - L[q] + 1);
    	}
    }
    LL query(int l, int r) {
    	int p = pos[l], q = pos[r];
    	LL ans = 0;
    	if (p == q) {
    		for (int i = l; i <= r; ++i) ans += a[i];
    		ans += add[p] * (r - l + 1);
    	} else {
    		for (int i = p + 1; i <= q - 1; ++i) ans += sum[i] + add[i] * (R[i] - L[i] + 1);
    		for (int i = l; i <= R[p]; ++i) ans += a[i];
    		ans += add[p] * (R[p] - l + 1);
    		for (int i = L[q]; i <= r; ++i) ans += a[i];
    		ans += add[q] * (r - L[q] + 1);
    	}
    	return ans;
    }
    int solve() {
    	n = read(); m = read();
    	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    	t = sqrt(n * 1.0);
    	for (int i = 1; i <= t; ++i) {
    		L[i] = (i - 1) * t + 1;
    		R[i] = i * t;
    	}
    	if (R[t] < n) t++, L[t] = R[t - 1] + 1, R[t] = n;
    	for (int i = 1; i <= t; ++i) {
    		for (int j = L[i]; j <= R[i]; ++j) {
    			pos[j] = i;
    			sum[i] += a[j];
    		}
        }
    	while (m--) {
    		int opt = read(), l = read(), r = read(), d;
    		if (opt == 1) {
                d = read();
    			change(l, r, d);
    		} else printf("%lld\n", query(l, r));
    	}
        return 0;
    }
};

/**
 * @brief 莫队算法
 */
struct CaptainMo {
    struct query {
        int l, r, id, pos;
    }q[maxn];
    bool cmp(query a, query b) {
        if (a.pos == b.pos) {
            if (a.pos % 2 == 1) return a.r < b.r;
            else return a.r > b.r;
        }
        return a.pos < b.pos;
    }
    int n, m, k, len, L, R, Ans;
    int ans[50010], c[50010], cnt[50010];
    void del(int x) {
        Ans -= (2 * cnt[c[x]] - 1); cnt[c[x]]--;
    }
    void add(int x) {
        Ans += (2 * cnt[c[x]] + 1); cnt[c[x]]++;
    }
    int solve(){
        n = read(); m = read(); k = read();
        len = sqrt(n);
        for (int i = 1; i <= n; ++i) c[i] = read();
        for (int i = 1; i <= m; ++i) {
            q[i].l = read(); q[i].r = read();
            q[i].id = i; q[i].pos = q[i].l / len + 1;
        }
        sort(q + 1, q + 1 + m, cmp); L = 1;
        for (int i = 1; i <= m; ++i) {
            while (L < q[i].l) del(L++);
            while (R > q[i].r) del(R--);
            while (L > q[i].l) add(--L);
            while (R < q[i].r) add(++R);
            ans[q[i].id] = Ans;
        }
        for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
        return 0;
    }
};

/**
 * @brief 左偏树
 */
struct LeftistTree {
    int n, m;
    struct LeftistTreeNode {
        int dis, val, rt;
        int ls, rs;
        #define ls(x)  tree[x].ls
        #define rs(x)  tree[x].rs
        #define dis(x) tree[x].dis
        #define val(x) tree[x].val
        #define rt(x)  tree[x].rt
    }tree[maxn];
    int merge(int x, int y) {
        if (!x || !y) return x + y;
        if (val(x) > val(y) || (val(x) == val(y) && x > y)) {
            swap(x, y);
        }
        rs(x) = merge(rs(x), y);
        if (dis(ls(x)) < dis(rs(x))) swap(ls(x), rs(x));
        rt(ls(x)) = rt(rs(x)) = rt(x) = x;
        dis(x) = dis(rs(x)) + 1;
        return x;
    }
    int get(int x) {
        return rt(x) == x ? x : rt(x) = get(rt(x));
    }
    void pop(int x) {
        val(x) = -1;
        rt(ls(x)) = ls(x); rt(rs(x)) = rs(x);
        rt(x) = merge(ls(x), rs(x));
    }
    void init() {
        dis(0) = -1;
        for (int i = 1; i <= n; ++i) {
            rt(i) = i;
            val(i) = read();
        }
    }
    void SolveMerge(int x, int y) {
        if (val(x) == -1 || val(y) == -1) return;
        int fx = get(x), fy = get(y);
        if (fx != fy) {
            rt(fx) = rt(fy) = merge(fx, fy);
        }
    }
    void SolvePop(int x) {
        if (val(x) == -1) puts("-1");
        else printf("%d\n", val(get(x))), pop(get(x));
    }
};

/**
 * @brief 二叉查找树
 */
struct BST {
    struct BSTNode {
        int l, r;
        int val;
    } a[maxn];
    int tot, root;
    int New(int val) {
        a[++tot].val = val;
        return tot;
    }
    void build() {
        New(-inf); New(inf);
        root = 1; a[1].r = 2;
    }
    int Get(int p, int val) {
        if (p == 0) return 0;
        if (val == a[p].val) return p;
        return val < a[p].val ? Get(a[p].l, val) : Get(a[p].r, val);
    }
    void insert(int& p, int val) {
        if (p == 0) {
            p = New(val);
            return;
        }
        if (val == a[p].val) return;
        if (val <  a[p].val) insert(a[p].l, val);
        else insert(a[p].r, val);
    }
    int getNext(int val) {
        int ans = 2, p = root;
        while (p) {
            if (val == a[p].val) {
                if (a[p].r > 0) {
                    p = a[p].r;
                    while (a[p].l > 0) p = a[p].l;
                    ans = p;
                }
                break;
            }
            if (a[p].val > val && a[p].val < a[ans].val) ans = p;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        return ans;
    }
    void remove(int val) {
        int& p = root;
        while (p) {
            if (val == a[p].val) break;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        if (p == 0) return;
        if (a[p].l == 0) p = a[p].r;
        else if (a[p].r == 0) p = a[p].l;
        else {
            int next = a[p].r;
            while (a[next].l > 0) next = a[next].l;
            remove(a[next].val);
            a[next].l = a[p].l;
            a[next].r = a[p].r;
            p = next;
        }
    }
};

/**
 * @brief 平衡树(Treap)
 */
struct Treap {
    struct TreapNode {
        int l, r;
        int val, dat;
        int cnt, size;
    } a[maxn];
    int tot, root, n;
    int New(int val) {
        a[++tot].val = val;
        a[tot].dat   = rand();
        a[tot].cnt   = 1;
        a[tot].size  = 1;
        return tot;
    }
    void update(int p) {
        a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
    }
    void build() {
        New(-inf); New(inf);
        root = 1;
        a[1].r = 2;
        update(root);
    }
    int GetRankByVal(int p, int val) {
        if (p == 0) return 0;
        if (val == a[p].val) return a[a[p].l].size + 1;
        if (val <  a[p].val) return GetRankByVal(a[p].l, val);
        return GetRankByVal(a[p].r, val) + a[a[p].l].size + a[p].cnt;
    }
    int GetValByRank(int p, int rank) {
        if (p == 0) return inf;
        if (a[a[p].l].size >= rank) return GetValByRank(a[p].l, rank);
        if (a[a[p].l].size + a[p].cnt >= rank) return a[p].val;
        return GetValByRank(a[p].r, rank - a[a[p].l].size - a[p].cnt);
    }
    void zig(int& p) {
        int q = a[p].l;
        a[p].l = a[q].r; a[q].r = p; p = q;
        update(a[p].r); update(p);
    }
    void zag(int& p) {
        int q = a[p].r;
        a[p].r = a[q].l; a[q].l = p; p = q;
        update(a[p].l); update(p);
    }
    void insert(int& p, int val) {
        if (p == 0) {
            p = New(val);
            return;
        }
        if (val == a[p].val) {
            a[p].cnt++; update(p);
            return;
        }
        if (val < a[p].val) {
            insert(a[p].l, val);
            if (a[p].dat < a[a[p].l].dat) zig(p);
        } else {
            insert(a[p].r, val);
            if (a[p].dat < a[a[p].r].dat) zag(p);
        }
        update(p);
    }
    int GetPre(int val) {
        int ans = 1, p = root;
        while (p) {
            if (val == a[p].val) {
                if (a[p].l > 0) {
                    p = a[p].l;
                    while (a[p].r > 0) p = a[p].r;
                    ans = p;
                }
                break;
            }
            if (a[p].val < val && a[p].val > a[ans].val) ans = p;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        return a[ans].val;
    }
    int GetNext(int val) {
        int ans = 2, p = root;
        while (p) {
            if (val == a[p].val) {
                if (a[p].r > 0) {
                    p = a[p].r;
                    while (a[p].l > 0) p = a[p].l;
                    ans = p;
                }
                break;
            }
            if (a[p].val > val && a[p].val < a[ans].val) ans = p;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        return a[ans].val;
    }
    void Remove(int& p, int val) {
        if (p == 0) return;
        if (val == a[p].val) {
            if (a[p].cnt > 1) {
                a[p].cnt--; update(p);
                return;
            }
            if (a[p].l || a[p].r) {
                if (a[p].r == 0 || a[a[p].l].dat > a[a[p].r].dat) {
                    zig(p); Remove(a[p].r, val);
                } else {
                    zag(p); Remove(a[p].l, val);
                }
                update(p);
            } else p = 0;
            return;
        }
        val < a[p].val ? Remove(a[p].l, val) : Remove(a[p].r, val);
        update(p);
    }
};

/**
 * @brief 伸展树(Splay)
 */
struct Splay {
    struct Node {
        int ch[2], fa;
        int cnt, val, size;
    } a[maxn];
    int root = 0, n, tot = 0;
    void update(int p) {
        a[p].size = a[a[p].ch[0]].size + a[a[p].ch[1]].size + a[p].cnt;
    }
    void rotate(int p) {
        int y = a[p].fa, z = a[y].fa, k = a[y].ch[1] == p;
        a[z].ch[a[z].ch[1] == y] = p;  a[p].fa = z;
        a[y].ch[k] = a[p].ch[k ^ 1];   a[a[p].ch[k ^ 1]].fa = y;
        a[p].ch[k ^ 1] = y;            a[y].fa = p;
        update(y); update(p);
    }
    void splay(int p, int goal) {
        while (a[p].fa != goal) {
            int y = a[p].fa;
            int z = a[y].fa;
            if (z != goal) {
                (a[y].ch[0] == p) ^ (a[z].ch[0] == y) ? rotate(p) : rotate(y);
            }
            rotate(p);
        }
        if (goal == 0) root = p;
    }
    void insert(int val) {
        int u = root, fa = 0;
        while (u && a[u].val != val) {
            fa = u;
            u = a[u].ch[val > a[u].val];
        }
        if (u) a[u].cnt++;
        else {
            u = ++tot;
            if (fa) a[fa].ch[val > a[fa].val] = u;
            a[tot].ch[0] = 0;
            a[tot].ch[1] = 0;
            a[tot].fa = fa; a[tot].val = val;
            a[tot].cnt = 1; a[tot].size = 1;
        }
        splay(u, 0);
    }
    void find(int val) {
        int u = root;
        if (!u) return;
        while (a[u].ch[val > a[u].val] && val != a[u].val) {
            u = a[u].ch[val > a[u].val];
        }
        splay(u, 0);
    }
    int Get(int val, int opt) {
        find(val);
        int u = root;
        if ((a[u].val > val && opt) || (a[u].val < val && !opt)) return u;
        u = a[u].ch[opt];
        while (a[u].ch[opt ^ 1]) u = a[u].ch[opt ^ 1];
        return u;
    }
    void Remove(int val) {
        int last = Get(val, 0);
        int next = Get(val, 1);
        splay(last, 0); splay(next, last);
        int del = a[next].ch[0];
        if (a[del].cnt > 1) {
            a[del].cnt--; 
            splay(del, 0);
        } else a[next].ch[0] = 0; 
    }
    int K_th(int rank) {
        int u = root;
        if (a[u].size < rank) return false;
        while (true) {
            int y = a[u].ch[0];
            if (rank > a[y].size + a[u].cnt) {
                rank -= a[y].size + a[u].cnt;
                u = a[u].ch[1];
            } else if (a[y].size >= rank) u = y;
            else return a[u].val;
        }
    }
    int GetRank() {
        return a[a[root].ch[0]].size;
    }
    int pre(int val) {
        return a[Get(val, 0)].val;
    }
    int suf(int val) {
        return a[Get(val, 1)].val;
    }
};