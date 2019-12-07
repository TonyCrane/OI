'''
 #  > File Name        : P1655.py
 #  > Author           : Tony_Wong
 #  > Created Time     : 2019/12/07 12:05:15
 #  > Algorithm        : Stirling II
'''

S = [[0] * 110 for i in range(110)]
for i in range(1, 110):
    S[i][i] = S[i][1] = 1
    for j in range(2, i):
        S[i][j] = S[i - 1][j - 1] + S[i - 1][j] * j

while True:
    try:
        _input = input().split()
        n = int(_input[0])
        m = int(_input[1])
        print(S[n][m])
    except EOFError:
        break