/*************************************************************
 *  > File Name        : P1201.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/19 15:59:41
 *  > Algorithm        : [STL]map
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

string name[15];
map<string, int> _map;

int main() {
    int np = read();
    for (int i = 1; i <= np; ++i) {
        cin >> name[i];
    }
    for (int i = 1; i <= np; ++i) {
        string str; cin >> str;
        int m = read(), p = read();
        int num = (p != 0) ? m / p : 0;
        _map[str] -= num * p;
        for (int j = 1; j <= p; ++j) {
            string str2; cin >> str2;
            _map[str2] += num;
        }
    }
    for (int i = 1; i <= np; ++i) {
        cout << name[i] << " " << _map[name[i]] << endl;
    }
    return 0;
}