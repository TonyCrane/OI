def IsPrime(num):
    for i in range(2, num):
        if num % i == 0:
            return False
    return True

fac = []

def solve(num):
    i = 2
    while i <= num:
        if not IsPrime(i):
            i += 1
            continue
        if num % i == 0:
            fac.append(i)
            num /= i
        else:
            i += 1

solve(600851475143)
print(fac[-1])