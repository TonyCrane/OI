/*************************************************************
 *  > File Name        : 1133.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/09 12:46:46
 *  > Algorithm        : [DataStructure]stack
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 2000010;

int n, ans, top1, top2;
int s1[maxn], s2[maxn];

void clears() {
    int now, val, i;
    while (top1) {
        val = s1[top1];
        for (i = top1; i; --i) {
            if (s1[top1] != s1[i - 1]) {
                break;
            }
        }
        now = top1 - i + 1;
        top1 = i - 1;
        while (now / 2) {
            s1[++top1] = val + 1;
            now -= 2;
        }
    }
    ans = max(ans, s1[1]);
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        int a = read();
        s2[++top2] = a;
        while (top2) {
            if (!top1) {
                s1[++top1] = s2[top2--];
            } else {
                if (s1[top1] > s2[top2]) {
                    s1[++top1] = s2[top2--];
                } else if (s1[top1] == s2[top2]) {
                    s1[++top1] = s2[top2--];
                } else if (s1[top1] < s2[top2]) {
                    if (top1 > 1 && s1[top1] == s1[top1 - 1]) {
                        s2[++top2] = s1[top1] + 1;
                        top1 -= 2;
                    } else {
                        top1--;
                        for (int j = 2; j <= top2; ++j) {
                            s1[++top1] = s2[j];
                        }
                        clears();
                    }
                }
            }
        }
        ans = max(ans, s1[top1]);
    }
    clears();
    printf("%d\n", ans);
    return 0;
}