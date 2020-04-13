f = [[0 for i in range(25)] for j in range(25)]

f[0][1] = 1
for i in range(1, 22):
    for j in range(1, 22):
        f[i][j] = f[i - 1][j] + f[i][j - 1]
print(f[21][21])