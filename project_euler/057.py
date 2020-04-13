a, b, ans = 1, 2, 0
for i in range(1000):
    if len(str(a + b)) > len(str(b)):
        ans += 1
    t = b
    b = a + b * 2
    a = t
print(ans)