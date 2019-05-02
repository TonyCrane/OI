/*************************************************************
 *  > File Name        : P2765.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/01 09:24:36
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> a[110];
bool can[4010];
int n, ans = 1, cnt;

int main() {
    scanf("%d", &n);
    for (int i = 1; i * i <= 4000; ++i) {
        can[i * i] = true;
    }
    while (true) {
        for (int i = 1; i <= cnt; ++i) {
            if (can[ ans + a[ i ][ a[i].size() - 1 ] ]) {
                a[i].push_back(ans++);
                i = 0;
                continue;
            }
        }
        if (cnt < n) {
            cnt++;
            a[cnt].push_back(ans++);
        } else break;
    }
    printf("%d\n", ans - 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}