/*************************************************************
 *  > File Name        : c1080_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/28 12:57:59
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

char str[maxn];
stack<char> s;
int ans;

int main() {
    scanf("%s", str); int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] == '(') {
            s.push('(');
        } else {
            if (!s.empty()) s.pop();
            else s.push('('), ++ans;
        }
    }
    printf("%d\n", (int)s.size() / 2 + ans);
    return 0;
}