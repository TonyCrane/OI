/*************************************************************
 *  > File Name        : U34632.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/11 06:45:31
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int main() {
    int id = read();
    if (id == 1) {
        printf("1\n");
        return 0;
    } else if (id == 2) {
        printf("WA\n");
        return 0;
    } else if (id == 3) {
        return -1;
    } else if (id == 4) {
        int i = 1;
        while (true) {
            i++;
        }
        return 0;
    } else if (id == 5) {
        while (true) {
            int* i = new int;
        }
        return 0;
    } else if (id == 6) {
        while (true) {
            printf("fjdksalfdjsaouerifjdijfiejfodjosjofjejfodjfodfojdofjodjgodmfodjfodjfoidjofjsofjsofjsojfosjfos\n");
        }
        return 0;
    } else if (id == 7) {
        printf("1\n");
        return 0;
    } else if (id == 8) {
        printf("8\n");
        return 0;
    }
}