/*************************************************************
 *  > File Name        : U78300.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/13 16:01:08
 *  > Algorithm        : 模拟
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 110;

int n, t;

struct Airplane {
    int x, y, z;
    int h, f;
    int atk, def, mat, mdf;
    int hp, fix;
    int act[maxn];
}p[maxn];

struct Direct {
    int x, y, z;
};

Direct HFtoDirect(int h, int f) {
    if (h == 0) {
        return (Direct){0, 0, -1};
    } else if (h == 4) {
        return (Direct){0, 0, 1};
    } else {
        if (h == 1) {
            if (f == 0) {
                return (Direct){1, 0, -1};
            } else if (f == 1) {
                return (Direct){1, 1, -1};
            } else if (f == 2) {
                return (Direct){0, 1, -1};
            } else if (f == 3) {
                return (Direct){-1, 1, -1};
            } else if (f == 4) {
                return (Direct){-1, 0, -1};
            } else if (f == 5) {
                return (Direct){-1, -1, -1};
            } else if (f == 6) {
                return (Direct){0, -1, -1};
            } else if (f == 7) {
                return (Direct){1, -1, -1};
            }
        } else if (h == 2) {
            if (f == 0) {
                return (Direct){1, 0, 0};
            } else if (f == 1) {
                return (Direct){1, 1, 0};
            } else if (f == 2) {
                return (Direct){0, 1, 0};
            } else if (f == 3) {
                return (Direct){-1, 1, 0};
            } else if (f == 4) {
                return (Direct){-1, 0, 0};
            } else if (f == 5) {
                return (Direct){-1, -1, 0};
            } else if (f == 6) {
                return (Direct){0, -1, 0};
            } else if (f == 7) {
                return (Direct){1, -1, 0};
            }
        } else if (h == 3) {
            if (f == 0) {
                return (Direct){1, 0, 1};
            } else if (f == 1) {
                return (Direct){1, 1, 1};
            } else if (f == 2) {
                return (Direct){0, 1, 1};
            } else if (f == 3) {
                return (Direct){-1, 1, 1};
            } else if (f == 4) {
                return (Direct){-1, 0, 1};
            } else if (f == 5) {
                return (Direct){-1, -1, 1};
            } else if (f == 6) {
                return (Direct){0, -1, 1};
            } else if (f == 7) {
                return (Direct){1, -1, 1};
            }
        }
    }
}

void read_data() {
    n = read(); t = read();
    for (int i = 1; i <= n; ++i) {
        p[i].x   = read();
        p[i].y   = read();
        p[i].z   = read();
        p[i].h   = read();
        p[i].f   = read();
        p[i].atk = read();
        p[i].def = read();
        p[i].mat = read();
        p[i].mdf = read();
        p[i].hp  = read();
        p[i].fix = read();
        char ch[maxn];
        scanf("%s", ch + 1);
        for (int j = 1; j <= t; ++j) {
            if      (ch[j] == 'N') p[i].act[j] = 0;
            else if (ch[j] == 'U') p[i].act[j] = 1;
            else if (ch[j] == 'D') p[i].act[j] = 2;
            else if (ch[j] == 'L') p[i].act[j] = 3;
            else if (ch[j] == 'R') p[i].act[j] = 4;
            else if (ch[j] == 'F') p[i].act[j] = 5;
            else if (ch[j] == 'A') p[i].act[j] = 6;
            else if (ch[j] == 'M') p[i].act[j] = 7;
        }
    }
}

void Move(int num) {
    Direct dir = HFtoDirect(p[num].h, p[num].f);
    p[num].x += dir.x;
    p[num].y += dir.y;
    p[num].z += dir.z;
}

void A(int num) {
    int lenm = -1, goal = num;
    for (int i = 1; i <= n; ++i) {
        if (i == num) continue;
        int dx = p[i].x - p[num].x;
        int dy = p[i].y - p[num].y;
        int dz = p[i].z - p[num].z;
        Direct dir = HFtoDirect(p[num].h, p[num].f);
        if ((dx == 0 && dir.x != 0) || (dy == 0 && dir.y != 0) || (dz == 0 && dir.z != 0)) continue;
        int kx = dir.x / dx, ky = dir.y / dy, kz = dir.z / dy;
        if (kx != ky || kx != kz || ky != kz || kx <= 0) continue;
        int len = dx * dx + dy * dy + dz * dz;
        if (len < lenm) goal = i;
    }
    if (goal != num) {
        int hurt = p[num].atk - p[goal].def;
        if (hurt > 0) {
            p[goal].hp -= hurt;
            if (p[goal].hp < 0) p[goal].hp = 0;
        }
    }
}

void M(int num) {
    int lenm = -1, cnt = 0;
    int goal[maxn];
    for (int i = 1; i <= n; ++i) {
        if (i == num) continue;
        int dx = p[i].x - p[num].x;
        int dy = p[i].y - p[num].y;
        int dz = p[i].z - p[num].z;
        Direct dir = HFtoDirect(p[num].h, p[num].f);
        if ((dx == 0 && dir.x != 0) || (dy == 0 && dir.y != 0) || (dz == 0 && dir.z != 0)) continue;
        int kx = dir.x / dx, ky = dir.y / dy, kz = dir.z / dy;
        if (kx != ky || kx != kz || ky != kz || kx <= 0) continue;
        goal[++cnt] = i;
    }
    for (int i = 1; i <= cnt; ++i) {
        int hurt = p[num].mat - p[goal[i]].mdf;
        if (hurt > 0) {
            p[goal[i]].hp -= hurt;
            if (p[goal[i]].hp < 0) p[goal[i]].hp = 0;
        }
    }
}

void Act(int num, int dt) {
    if (p[num].act[dt] == 0) return;
    if        (p[num].act[dt] == 1) {
        if (p[num].h == 4) return;
        p[num].h += 1;
    } else if (p[num].act[dt] == 2) {
        if (p[num].h == 0) return;
        p[num].h -= 1;
    } else if (p[num].act[dt] == 3) {
        if (p[num].f == 7) p[num].f = 0;
        else p[num].f += 1;
    } else if (p[num].act[dt] == 4) {
        if (p[num].f == 0) p[num].f = 7;
        else p[num].f -= 1;
    } else if (p[num].act[dt] == 5) {
        p[num].hp += p[num].fix;
    } else if (p[num].act[dt] == 6) {
        A(num);
    } else if (p[num].act[dt] == 7) {
        M(num);
    }
}

int main() {
    read_data();
    for (int dt = 1; dt <= t; ++dt) {
        for (int num = 1; num <= n; ++num) {
            if (p[num].hp <= 0) continue;
            Move(num);
        }
        for (int num = 1; num <= n; ++num) {
            if (p[num].hp <= 0) continue;
            Act(num, dt);
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d %d %d %d\n", p[i].x, p[i].y, p[i].z, p[i].hp);
    }
    return 0;
}