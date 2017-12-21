cost = float(input())
lawns = int(input())
total = 0

for _ in range(lawns):
    x,y = map(float, input().split())
    total += x*y*cost

print(total)
