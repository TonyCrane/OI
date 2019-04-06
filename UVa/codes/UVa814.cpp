/*************************************************************
 *  > File Name        : UVa814.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/02/06 14:47:20
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

void parse_address(const string& s, string& usr, string& mta)
{
    int k = s.find("@");
    usr   = s.substr(0, k);
    mta   = s.substr(k + 1);
}

int main()
{
    int k;
    string s, t, usr1, usr2, mta1, mta2;
    set<string> addr;

    while (cin >> s && s != "*")
    {
        cin >> s >> k;
        while (k--)
        {
            cin >> t;
            addr.insert(t + "@" + s);
        }
    }

    while (cin >> s && s != "*")
    {
        parse_address(s, usr1, mta1);
        vector<string> mta;
        map<string, vector<string> > dest;
        set<string> vis;
        while (cin >> t && t != "*")
        {
            parse_address(t, usr2, mta2);
            if (vis.count(t)) continue;
            vis.insert(t);
            if (!dest.count(mta2))
            {
                mta.push_back(mta2);
                dest[mta2] = vector<string>();
            }
            dest[mta2].push_back(t);
        }

        getline(cin, t);

        string data;
        while (getline(cin, t) && t[0] != '*')
            data += "     " + t + "\n";
        for (int i = 0; i < mta.size(); ++i)
        {
            string mta2 = mta[i];
            vector<string> usrs = dest[mta2];
            cout << "Connection between " << mta1 << " and " << mta2 << endl;
            cout << "     HELO " << mta1 << endl;
            cout << "     250\n";
            cout << "     MAIL FROM:<" << s << ">\n";
            cout << "     250\n";
            bool ok = false;
            for (int i = 0; i < usrs.size(); ++i)
            {
                cout << "     RCPT TO:<" << usrs[i] << ">\n";
                if (addr.count(usrs[i]))
                {
                    ok = true;
                    cout << "     250\n";
                }
                else cout << "     550\n";
            }
            if (ok)
            {
                cout << "     DATA\n"; cout << "     354\n";
                cout << data;
                cout << "     .\n"; cout << "     250\n";
            }
            cout << "     QUIT\n"; cout << "     221\n";
        }
    }
    return 0;
}