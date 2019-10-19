import random

n = 1000
m = 1000

print(n)

for i in range(1, n + 1):
    print(str(int(random.random() * 1000000000 + 1)) + " ", end='')
print("")

print(m)
for i in range(1, m + 1):
    l = int(random.random() * 999) + 1
    r = int(random.random() * 999) + 1
    if l > r:
        tmp = l
        l = r
        r = tmp
    print(str(l) + " " + str(r))