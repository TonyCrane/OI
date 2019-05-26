/*************************************************************
 *  > File Name        : P2580_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/26 17:03:47
 *  > Algorithm        : [字符串]Trie
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 500010;

struct Trie {
    int ch[maxn][26], sz, val[maxn];
    Trie() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset( val , 0, sizeof( val ));
    }
    int idx(char c) { return c - 'a'; }
    void insert(char *s) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
    }
    int search(char *s) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) return 0;
            u = ch[u][c];
        }
        if (!val[u]) return val[u] = 1, 1;
        return 2;
    }
}trie;

int main() {
    int n = read(); char s[100];
    for (int i = 1; i <= n; ++i) scanf("%s", s), trie.insert(s);
    int m = read();
    for (int i = 1; i <= m; ++i) {
        scanf("%s", s);
        int opt = trie.search(s);
        if (opt == 0) puts("WRONG");
        else if (opt == 1) puts("OK");
        else puts("REPEAT");
    }
    return 0;
}