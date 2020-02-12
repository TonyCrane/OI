import sys

n = 1000
for a in range(1, n + 1):
    for b in range(a + 1, n + 1):
        c = n - a - b
        if a * a + b * b == c * c:
            print(a * b * c)
            sys.exit(0)