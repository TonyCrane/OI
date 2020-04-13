def IsPrime(num):
    for i in range(2, num):
        if num % i == 0:
            return False
    return True

now = 2
cnt = 0
while True:
    if IsPrime(now):
        cnt += 1
        if cnt == 10001:
            print(now)
            break
    now += 1