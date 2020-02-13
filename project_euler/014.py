import sys

sys.setrecursionlimit(10000)

def Collatz(num):
    if num == 1:
        return 1
    if num % 2 == 0:
        return Collatz(num / 2) + 1
    return Collatz(3 * num + 1) + 1

print(max(range(1, 1000000), key = Collatz))