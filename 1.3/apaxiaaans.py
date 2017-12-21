name = list(input())
temp = ''
names = ''
for i in name:
    if (i != temp):
        names += i
    temp = i

print(names)

