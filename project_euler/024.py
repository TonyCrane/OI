import itertools

arr = list(range(10))
per = list(itertools.permutations(arr))
print("".join(str(i) for i in per[999999]))