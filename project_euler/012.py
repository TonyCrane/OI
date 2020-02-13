import math, itertools

def divisorsCount(num):
    n = math.floor(math.sqrt(num))
    res = sum(2 for i in range(1, n + 1) if num % i == 0)
    if n ** 2 == num:
        res -= 1
    return res

tri = 0
for i in itertools.count(1):
    tri += i
    if divisorsCount(tri) > 500:
        print(tri)
        break