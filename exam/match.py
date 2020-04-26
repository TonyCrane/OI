import random
n = 20
print(n)
for i in range(n):
    print(random.randint(0, 1), end="")
print("")
for i in range(n - 1):
    u = random.randint(1, n)
    v = random.randint(1, n)
    while u == v:
        v = random.randint(1, n)
    print(u, end=" ")
    print(v)