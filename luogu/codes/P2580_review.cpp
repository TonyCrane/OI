/*************************************************************
 *  > File Name        : P2580_review.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 10:09:56
 *  > Algorithm        : review Trie
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
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
        memset(val, 0, sizeof(val));
    }
    void insert(char* str) {
        int p = 1, len = strlen(str);
        for (int i = 0; i < len; ++i) {
            int c = str[i] - 'a';
            if (!ch[p][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                ch[p][c] = sz++;
            }
            p = ch[p][c];
        }
    }
    int search(char* str) {
        int p = 1, len = strlen(str);
        for (int i = 0; i < len; ++i) {
            int c = str[i] - 'a';
            if (!ch[p][c]) return -1;
            p = ch[p][c];
        }
        if (!val[p]) {
            val[p] = 1; return 1;
        }
        return 0;
    }
}trie;

int main() {
    int n = read(); char str[60];
    for (int i = 1; i <= n; ++i) {
        scanf("%s", str);
        trie.insert(str);
    }
    int m = read();
    for (int i = 1; i <= m; ++i) {
        scanf("%s", str);
        int res = trie.search(str);
        if (res == -1) puts("WRONG");
        else if (res == 1) puts("OK");
        else if (res == 0) puts("REPEAT");
    }
    return 0;
}