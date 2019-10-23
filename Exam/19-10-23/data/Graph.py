from random import *

n = 100000
m = randint(50000, 100000)
k = randint(50000, 100000)

print(str(n) + " " + str(m) + " " + str(k))

for i in range(m):
    u = randint(1, n)
    v = randint(1, n)
    w = randint(1, 1000)
    print(str(u) + " " + str(v) + " " + str(w))

print()

for i in range(k):
    x = randint(1, 1000)
    print(x)