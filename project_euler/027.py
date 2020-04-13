def IsPrime(num):
    if num <= 1:
        return False
    for i in range(2, int(num ** 0.5 + 1)):
        if num % i == 0:
            return False
    return True

ans = []
res, now = 0, 0

for a in range(-999, 1000):
    for b in range(2, 1001):
        for n in range(100):
            num = n * n + n * a + b
            if IsPrime(num):
                res = n
                continue
            else:
                break
        if now < res:
            now = res
            ans = [a, b]
print(ans[0] * ans[1])