"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 #  > File Name        : P1080.py
 #  > Author           : Tony
 #  > Created Time     : 2019/06/13 15:14:45
 #  > Algorithm        : [Greedy]
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

n = int(input())
s = input().split()
S = int(s[0])
T = int(s[1])
a = []
ans = 0

for i in range(1, n + 1):
    k = input().split()
    a.append((int(k[0]), int(k[1])))

a.sort(key = lambda x : x[0] * x[1])

for i in range(0, n):
    if S // (a[i])[1] > ans:
        ans = S // (a[i])[1]
    S *= (a[i])[0]

print(ans)