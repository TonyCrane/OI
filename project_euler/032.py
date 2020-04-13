from math import floor, sqrt

def valid(num):
    for i in range(1, floor(sqrt(num)) + 1):
        if num % i != 0:
            continue
        s = str(num) + str(i) + str(num // i)
        if "".join(sorted(s)) == "123456789":
            return True
    return False

print(sum(i for i in range(1, 10000) if valid(i)))