#include <bits/stdc++.h>
using namespace std;

int a[100];

int main() {
    for (int i = 0; i <= 99; ++i) a[i] = i;
    for (auto i : a) {
        printf("%d\n", i);
    }
    return 0;
}