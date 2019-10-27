/*************************************************************
 *  > File Name        : T104062.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/27 13:38:50
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, q;
map<string, string> m;

int main() {
    scanf("%d %d\n", &n, &q);
    for (int i = 1; i <= n; ++i) {
        string str1, str2;
        cin >> str1 >> str2;
        m[str1] = str2;
    }
    for (int i = 1; i <= q; ++i) {
        string ques, ansA, ansB, ansC, ansD;
        cin >> ques >> ansA >> ansB >> ansC >> ansD;
        if (m[ques] == ansA) {
            printf("A\n");
            continue;
        } else if (m[ques] == ansB) {
            printf("B\n");
            continue;
        } else if (m[ques] == ansC) {
            printf("C\n");
            continue;
        } else {
            printf("D\n");
            continue;
        }
    }
    return 0;
}