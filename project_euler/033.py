from math import gcd

up, down = 1, 1
for d in range(10, 100):
    for n in range(10, d):
        n1 = n // 10
        n0 = n % 10
        d1 = d // 10
        d0 = d % 10
        if (n1 == d0 and n0 * d == n * d1) or (n0 == d1 and n1 * d == n * d0):
            up *= n
            down *= d
print(down // gcd(up, down))