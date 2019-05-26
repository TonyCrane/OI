/*************************************************************
 *  > File Name        : P2580.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/26 16:34:37
 *  > Algorithm        : [STL]map
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
map<string, int> _map;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) cin >> s, _map[s] = 1;
    scanf("%d", &n);
    while (n--) {
        cin >> s;
        if (_map[s] == 1) puts("OK"), _map[s] = 2;
        else if (_map[s] == 2) puts("REPEAT");
        else puts("WRONG");
    }
    return 0;
}