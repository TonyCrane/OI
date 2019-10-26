/*************************************************************
 *  > File Name        : CF1251A.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/26 15:08:30
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 600;
char str[maxn];
bool valid[30];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%s", str); int n = strlen(str);
        memset(valid, 0, sizeof(valid));
        for (int i = 0; i < n;) {
            int cnt = 1;
            while (str[i] == str[i + 1]) i++, cnt++;
            if (cnt % 2 == 1) valid[str[i] - 'a'] = true;
            i++;
        }
        for (int i = 0; i < 26; ++i) {
            if (valid[i]) printf("%c", i + 'a');
        }
        printf("\n");
    }
    return 0;
}