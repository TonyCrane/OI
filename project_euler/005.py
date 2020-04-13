from math import gcd

ans = 1
for i in range(1, 21):
    ans *= i // gcd(i, ans)
print(ans)