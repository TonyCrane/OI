import itertools

def getLen(num):
    vis = {}
    now = 1
    for i in itertools.count():
        if now in vis:
            return i - vis[now]
        else:
            vis[now] = i
            now = now * 10 % num
    
print(max(range(1, 1000), key=getLen))