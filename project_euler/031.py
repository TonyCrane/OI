f = [0 for i in range(201)]
f[0] = 1
for coin in [1, 2, 5, 10, 20, 50, 100, 200]:
    for i in range(len(f) - coin):
        f[i + coin] += f[i]
print(f[-1])