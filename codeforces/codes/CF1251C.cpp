/*************************************************************
 *  > File Name        : CF1251C.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/26 16:04:12
 *  > Algorithm        : merge sort
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 300010;

char str[maxn];
char odd[maxn], even[maxn];

void work(int cnto, int cnte) {
    int i = 1, j = 1, k = 0;
    while (i <= cnto && j <= cnte) {
        if (odd[i] < even[j]) {
            printf("%c", odd[i++]);
        } else {
            printf("%c", even[j++]);
        }
    }
    while (i <= cnto) printf("%c", odd[i++]);
    while (j <= cnte) printf("%c", even[j++]);
}

int main() {
    int T = read();
    while (T--) {
        scanf("%s", str); int len = strlen(str);
        int cnto = 0, cnte = 0;
        for (int i = 0; i < len; ++i) {
            if (str[i] % 2 == 0) even[++cnte] = str[i];
            else odd[++cnto] = str[i];
        }
        work(cnto, cnte);
        printf("\n");
    }
    return 0;
}