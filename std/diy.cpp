#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    //freopen("diy.in", "r", stdin);
    //freopen("diy.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        if(n % 3 == 0) {
            int t = n / 3;
            cout << t * 1LL * t * t << '\n';
        } else if(n % 4 == 0) {
            int t1 = n / 2;
            int t2 = n / 4;
            cout << t1 * 1LL * t2 * t2 << '\n';
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
