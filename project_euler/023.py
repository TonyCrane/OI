n = 28124
div = [0 for i in range(n)]
for i in range(1, n):
    for j in range(i * 2, n, i):
        div[j] += i
nums = [i for (i, x) in enumerate(div) if x > i]
vis = [False for i in range(n)]
for i in nums:
    for j in nums:
        if i + j < n:
            vis[i + j] = True
        else:
            break
print(sum(i for (i, j) in enumerate(vis) if not j))