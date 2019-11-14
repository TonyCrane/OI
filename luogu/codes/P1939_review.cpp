/*************************************************************
 *  > File Name        : P1939_review.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/14 20:15:19
 *  > Algorithm        : review Matrix
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int mod = 1000000007;

struct Matrix {
    LL mat[3][3];
    Matrix() { memset(mat, 0, sizeof(mat)); }
    Matrix operator * (const Matrix& a) const {
        Matrix res; memset(res.mat, 0, sizeof(res.mat));
        for (LL i = 0; i <= 2; ++i) {
            for (LL j = 0; j <= 2; ++j) {
                for (LL k = 0; k <= 2; ++k) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * a.mat[k][j]) % mod;
                }
            }
        }
        return res;
    }
}Base, Ans;

void Matrix_pow(LL pow) {
    while (pow) {
        if (pow & 1) Ans = Ans * Base;
        Base = Base * Base;
        pow >>= 1;
    }
}

int main() {
    int T = read();
    while (T--) {
        int n = read();
        Base.mat[0][0] = 1; Base.mat[0][1] = 0; Base.mat[0][2] = 1;
        Base.mat[1][0] = 1; Base.mat[1][1] = 0; Base.mat[1][2] = 0;
        Base.mat[2][0] = 0; Base.mat[2][1] = 1; Base.mat[2][2] = 0;
        Ans.mat[0][0] = Ans.mat[0][1] = Ans.mat[0][2] = 1;
        if (n > 3) Matrix_pow(n - 3);
        printf("%lld\n", Ans.mat[0][0] % mod);
    }
    return 0;
}