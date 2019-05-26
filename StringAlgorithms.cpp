/*************************************************************
 *  > Description      : 字符串算法模板
 *  > File Name        : StringAlgorithms.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/26 17:26:25
 *  > Copyright (C) 2019 Tony
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;

/**
 * @brief KMP算法
 * @param[in]  s1,s2,l1,l2
 */
char s1[maxn], s2[maxn]; int l1, l2, nxt[maxn];
void pre() {
    nxt[1] = 0;
    int j = 0;
    for (int i = 1; i < l2; ++i) {
        while (j > 0 && s2[j + 1] != s2[i + 1]) j = nxt[j];
        if (s2[j + 1] == s2[i + 1]) j++;
        nxt[i + 1] = j;
    }
}
void kmp() {
    int j = 0;
    for (int i = 0; i < l1; ++i) {
        while (j > 0 && s2[j + 1] != s1[i + 1]) j = nxt[j];
        if (s2[j + 1] == s1[i + 1]) j++;
        if (j == l2) {
            printf("%d\n", i - l2 + 2);
            j = nxt[j];
        }
    }
}

/**
 * @brief Trie字典树
 */
struct Trie {
    int ch[maxn][26], sz, val[maxn];
    Trie() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset( val , 0, sizeof( val ));
    }
    int idx(char c) { return c - 'a'; }
    void insert(char *s, int v) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
    int search(char *s) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) return -1;
            u = ch[u][c];
        }
        return val[u];
    }
};

/**
 * @brief AC自动机
 */
int m; char s[maxn][maxn];
struct AC_Automata {
    int ch[maxn][26], val[maxn], fail[maxn], last[maxn], cnt[maxn], nodecnt;
    void init() {
        memset( ch , 0, sizeof( ch ));
        memset(val , 0, sizeof(val ));
        memset(cnt , 0, sizeof(cnt ));
        memset(fail, 0, sizeof(fail));
        memset(last, 0, sizeof(last));
        nodecnt = 0;
    }
    int idx(char c) { return c - 'a'; }
    void insert(char *s) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) ch[u][c] = ++nodecnt;
            u = ch[u][c];
        }
        val[u]++;
    }
    void getFail() {
        queue<int> q; q.push(0);
        while (!q.empty()) {
            int u = q.front(), k = fail[u]; q.pop();
            for (int c = 0; c < 26; ++c) {
                int v = ch[u][c];
                if (!v) { ch[u][c] = ch[k][c]; continue; }
                q.push(v);
                fail[v] = u ? ch[k][c] : 0;
                last[v] = val[fail[v]] ? fail[v] : last[fail[v]];
            }
        }
    }
    int count(char *s) {
        int u = 0, n = strlen(s), res = 0;
        for (int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            u = ch[u][c];
            if (val[u]) res += val[u], val[u] = 0;
            int v = u;
            while (last[v]) {
                v = last[v];
                if (val[v]) res += val[v], val[v] = 0;
            }
        }
        return res;
    }
    void query(char * T) {
        int u = 0, n = strlen(T), res = 0;
        for (int i = 0; i < n; ++i) {
            int c = idx(T[i]);
            u = ch[u][c];
            if (val[u]) cnt[val[u]]++;
            int v = last[u];
            while (v) {
                if (val[v]) cnt[val[v]]++;
                v = last[v];
            }
        }
        for (int i = 1; i <= m; ++i) res = max(res, cnt[i]);
        printf("%d\n", res);
        for (int i = 1; i <= m; ++i) if (cnt[i] == res) printf("%s\n", s[i]);
        return;
    }
};