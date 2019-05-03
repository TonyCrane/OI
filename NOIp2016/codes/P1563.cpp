/*************************************************************
 *  > File Name        : P1563.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/03 17:07:13
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int towards;
    string name;
} a[100001];

int n, m, ai, si;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].towards >> a[i].name;
    }
    int peo = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> ai >> si;
        if (ai == 0 && a[peo].towards == 0) peo = (peo + n - si) % n;
        else if (ai == 0 && a[peo].towards == 1) peo = (peo + si) % n;
        else if (ai == 1 && a[peo].towards == 0) peo = (peo + si) % n;
        else if (ai == 1 && a[peo].towards == 1) peo = (peo + n - si) % n;
    } 
    cout << a[peo].name << endl;
    return 0;
} 