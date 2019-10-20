/*************************************************************
 *  > File Name        : T103285.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/20 14:32:38
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1000010;

string str;
int n;
bool z = false;
string x, y;

int main() {
    cin >> str; n = str.length();
    if (str[n - 1] == 'Z') z = true;
    for (int i = n - 2; i >= 0; --i) {
        if (str[i] == 'Z' && !z) {
            printf("-1\n");
            return 0;
        }
        if (str[i] != 'Z') z = false;
    }
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'X') {
            x.append("2");
            y.append("1");
        } else if (str[i] == 'Y') {
            x.append("1");
            y.append("2");
        } else if (str[i] == 'Z') {
            x.append("1");
            y.append("1");
        }
    }
    cout << x << "\n" << y << endl;
    return 0;
}