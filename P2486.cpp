/*************************************************************
 *  > File Name        : P2486.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/23 21:12:40
 *  > Algorithm        : TreeChainSplit
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 10010;

