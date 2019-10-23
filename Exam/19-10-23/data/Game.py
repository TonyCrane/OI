from random import *

n = 500000
R = randint(400000, 500000)
k = randint(int(1e9), int(1e18))

print(str(n) + " " + str(R) + " " + str(k))

for i in range(n):
    a = randint(int(1e6), int(1e9))
    print(str(a) + " ", end='')

print()