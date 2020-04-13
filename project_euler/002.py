f = []
f.append(1)
f.append(2)
ans = 2
index = 3
while True:
    now = f[index - 2] + f[index - 3]
    if now > 4000000:
        break
    if now % 2 == 0:
        ans += now
    f.append(now)
    index += 1

print(ans)