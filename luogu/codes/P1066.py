'''
 #  > File Name        : P1066.py
 #  > Author           : Tony
 #  > Created Time     : 2019/10/11 21:24:18
 #  > Algorithm        : DP
'''

input_ = input().split()
k = int(input_[0])
W = int(input_[1])

l = int((W - 1) / k) + 1
dp = [[0 for i in range((1 << k) + 10)] for i in range(l + 10)]

for i in range(0, 1 << k):
    dp[0][i] = (1 << k) - i

for i in range(1, l):
    for j in range(0, 1 << k):
        dp[i][(1 << k) - j - 1] = dp[i][(1 << k) - j] + dp[i - 1][(1 << k) - j]

ans = 0
for i in range(1, l):
    ans += dp[i][1]

print(ans - dp[l - 1][1 << (W - k * (l - 1))])