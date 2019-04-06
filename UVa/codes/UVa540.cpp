#include <bits/stdc++.h>
using namespace std;

const int maxt = 1010;

int t, cnt;

int main()
{
    while (scanf("%d", &t) == 1 && t)
    {
        printf("Scenario #%d\n", ++cnt);

        map<int, int> team;
        for (int i = 0; i < t; ++i)
        {
            int n, x;
            scanf("%d", &n);
            while (n--)
            {
                scanf("%d", &x);
                team[x] = i;
            }
        }

        queue<int> q, q2[maxt];
        while (true)
        {
            int x;
            char cmd[10];
            scanf("%s", cmd);
            if (cmd[0] == 'S') break;
            else if (cmd[0] == 'D')
            {
                int t = q.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if (q2[t].empty())
                    q.pop();
            }
            else if (cmd[0] == 'E')
            {
                scanf("%d", &x);
                int t = team[x];
                if (q2[t].empty())
                    q.push(t);
                q2[t].push(x);
            }
        }
        printf("\n");    
    }
    return 0;
}