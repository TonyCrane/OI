from random import *
from math import *

T = 1000000
maxn = 10000000

print(T)

# for i in range(T):
#     n = randint(1, maxn)
#     print(n)

file = open("prime", "r")
prime = file.readlines()

for i in range(T):
    j = randint(0, len(prime) - 1)
    n = prime[j]
    print(n, end='')