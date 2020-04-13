vis = [0 for i in range(2000100)]
primes = []
def getPrimes(n):
    for i in range(2, n + 1):
        if vis[i] == 0:
            vis[i] = i
            primes.append(i)
        for j in range(0, len(primes)):
            if primes[j] > vis[i] or primes[j] > n / i:
                break
            vis[i * primes[j]] = primes[j]

ans = 0
getPrimes(2000000)
for prime in primes:
    ans += prime
print(ans)