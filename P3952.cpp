/*************************************************************
 *  > File Name        : P3952.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月17日 星期三 16时07分14秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int T, cal, O, NumOfLoop, var[100], Kill, ONow, Omax;
bool vis[30], CanRun, AddO[100];
string str1, str2;

int main() {
	cin >> T;
	while (T--) {
		cal = 0; NumOfLoop = 0; CanRun = 1;
		memset(vis, 0, sizeof(vis));
		memset(AddO, 0, sizeof(AddO));
		cin >> cal++ >> str1;

		if (str1[2] == '1') {
			O = 0;
		} else {
			O = str1[4] - '0';
		}

		while (cal--) {
			cin >> str1;
			if (str1[0] == 'F') {
				NumOfLoop++; cin >> str1;
				if (vis[str1[0] - 'a']) {
					NumOfLoop = -1;
				} else {
					vis[str1[0] - 'a'] = true;
					var[NumOfLoop] = str1[0] - 'a';
				}
				cin >> str1 >> str2;
				if (str1[0] != 'n' && str2[0] == 'n' && CanRun) {
					ONow++; AddO[NumOfLoop] = true;
				} else if (((str1.length() == str2.length() && str1 > str2) || (str1.length() > str2.length()) || (str1[0] == 'n' && str2[0] != 'n')) && CanRun == 0) {
					CanRun = false;
					Kill = NumOfLoop;
				}
			} else {
				Omax = max(Omax, Onow);
				vis[var[NumOfLoop]] = false;
				if (AddO[NumOfLoop]) {
					ONow--;
					AddO[NumOfLoop] = false;
				}
				NumOfLoop--;
			}
		}
	}
	return 0;
}
