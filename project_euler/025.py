f = [0 for i in range(100010)]
f[1] = 1
f[2] = 1
index = 3
while True:
    new = f[index - 1] + f[index - 2]
    if sum(1 for c in str(new)) >= 1000:
        print(index)
        break
    f[index] = new
    index += 1