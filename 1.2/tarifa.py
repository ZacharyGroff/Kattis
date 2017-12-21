x = int(input())
n = int(input())
total = x*n

for i in range(0,n):
    total -= int(input())

total += x
print(total)
