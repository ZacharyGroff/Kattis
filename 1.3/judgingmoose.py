l,r = map(int, input().split())

if (l == 0 and r == 0):
    print('Not a moose')
elif (l != r):
    print('Odd', max(l,r) * 2)
else:
    print('Even', l + r)
