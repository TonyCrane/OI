/*************************************************************
 *  > File Name        : P1947.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/05/08 07:59:56
 *  > Algorithm        : 交互 二分
**************************************************************/

extern "C" int Seniorious(int);

extern "C" int Chtholly(int n, int c) {
    int ans = 1, l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (Seniorious(mid) >= 0) {
            r = mid - 1; ans = mid;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}