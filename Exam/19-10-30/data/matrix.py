from random import *

n = 8000
m = 100000
q = randint(100, 256)

print(str(n) + " " + str(m) + " " + str(q))

for i in range(m):
    opt = randint(1, 2)
    x1 = randint(1, n)
    x2 = randint(1, n)
    y1 = randint(1, n)
    y2 = randint(1, n)
    print(str(opt) + " " + str(x1) + " " + str(x2) + " " + str(y1) + " " + str(y2))