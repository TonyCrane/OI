def judge(num):
    return str(num) == str(num)[::-1]

ans = 0
for i in range(100, 1000):
    for j in range(100, 1000):
        if judge(i * j):
            if i * j > ans:
                ans = i * j

print(ans)