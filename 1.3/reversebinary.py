myInt = int(input())
myInt = str('{0:b}'.format(myInt))[::-1]

print(int(myInt, 2))
