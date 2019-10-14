/*************************************************************
 *  > File Name        : P2264.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/14 20:49:10
 *  > Algorithm        : set
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 110;

set<string> key, s;
int ans;

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        string str; cin >> str;
        for (int j = 0; j < str.length(); ++j) {
            if (str[j] >= 'A' && str[j] <= 'Z') {
                str[j] += 32;
            }
        }
        key.insert(str);
    }
    string word; char ch = getchar();
    while (scanf("%c", &ch) == 1) {
        if (ch == '\n') break;
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            if (ch >= 'A' && ch <= 'Z') {
                ch += 32;
            }
            word.push_back(ch);
        } else {
            if (!word.empty()) {
                if (key.count(word)) s.insert(word);
                word.clear();
            }
            if (ch == '.') {
                ans += s.size(); s.clear();
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}