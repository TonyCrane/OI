/*************************************************************
 *  > File Name        : P3952.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月17日 星期三 16时07分14秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

string str1, str2;      
int cal, O, NumOfLoop, vis[27], var[27], Onow, Kill, AddO[100], Omax, WhereKill, T;

int main() {
    cin >> T;
    while (T > 0) {
		T--;
        cal = 0; O = 0; Omax = 0; WhereKill = 0; NumOfLoop = 0; Onow = 0; Kill = 0;
        memset(vis, 0, sizeof(vis));
		memset(AddO, 0, sizeof(AddO));
        do {
			str1 = str2;
			cin >> str2;
		} while(str2[0] != 'O');
        for (int i = 0; i < str1.length(); i++) cal = cal * 10 + str1[i] - '0';
        for (int i = 4; i < str2.length() - 1; i++) O = O * 10 + str2[i] - '0';
        while (cal > 0) {
			cal--;
            cin >> str1;
            if (str1[0] == 'F') {
                NumOfLoop++;
				cin >> str1;
                if (vis[str1[0] - 96]) {
					NumOfLoop = -1;
				} else { 
                	vis[str1[0] - 96] = 1;
					var[NumOfLoop] = str1[0] - 96;
				} 
                cin >> str1 >> str2;
                if (str1[0] != 'n' && str2[0] == 'n' && Kill == 0) {
					Onow++;
					AddO[NumOfLoop] = 1;
				} else if (((str1.length() == str2.length() && str1 > str2) || (str1.length() > str2.length()) || (str1[0] == 'n' && str2[0] != 'n')) && Kill == 0) {
					Kill = 1;
					WhereKill = NumOfLoop;
				}
            } else { 
                Omax = max(Omax, Onow);
				vis[var[NumOfLoop]] = 0; 
                if (AddO[NumOfLoop] == 1) {
					Onow--;
					AddO[NumOfLoop] = 0;
				} 
                NumOfLoop--; 
                if (WhereKill > 0 && NumOfLoop < WhereKill) {
					Kill = 0; WhereKill = 0;
				} 
            }
            if(NumOfLoop == -1) {
				printf("ERR\n");
				cal = -1;
			} 
        }
        if (NumOfLoop > 0) printf("ERR\n"); 
        if (NumOfLoop == 0 && Omax == O) printf("Yes\n");
        if (NumOfLoop == 0 && Omax != O) printf("No\n"); 
    }
    return 0;
}
