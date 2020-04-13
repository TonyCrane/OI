res1, res2 = 0, 0
for i in range(1, 101):
    res1 += i ** 2
    res2 += i
res2 = res2 ** 2
print(res2 - res1)