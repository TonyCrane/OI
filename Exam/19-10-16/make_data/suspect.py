from random import *

n = 1000
p = randint(300, 1000)

print(str(n) + " " + str(p))

for i in range(1, n + 1):
    x = randint(1, n)
    y = randint(1, n)
    while x == i:
        x = randint(1, n)
    while y == i and x == y:
        y = randint(1, n)
    print(str(x) + " " + str(y))