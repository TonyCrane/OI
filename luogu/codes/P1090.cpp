/*************************************************************
 *  > File Name        : P1090.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/14 12:38:43
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, a, ans;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        pq.push(a);
    }
    while (pq.size() >= 2) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        ans += x + y;
        pq.push(x + y);
    }
    printf("%d\n", ans);
    return 0;
}