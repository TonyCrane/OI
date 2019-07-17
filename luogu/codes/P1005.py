inp = raw_input()
n, m = inp.split(' ')
n = int(n)
m = int(m)
lis = list()
tmp = 2

for i in range(m):
    lis.append(tmp)
    tmp = tmp * 2

ans = 0
for i in range(n):
    inp = raw_input()
    num = [int(j) for j in inp.split(' ')]
    dp  = [[0 for j in range(m)] for k in range(m)]
    for j in range(m):
        dp[0][j] = num[j] * lis[m - 1]
    for j in range(1, m):
        for k in range(m - j):
            tmp1 = dp[j - 1][k] + num[j + k] * lis[m - 1 - j]
            tmp2 = dp[j - 1][k + 1] + num[k] * lis[m - 1 - j]
            if tmp1 > tmp2:
                dp[j][k] = tmp1
            else:
                dp[j][k] = tmp2
    ans += dp[m - 1][0]

print(ans)