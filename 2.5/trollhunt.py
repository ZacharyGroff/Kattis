b,k,g = input().split()
b = int(b) - 1
group = int(k) // int(g)
days = int(b) // group

if (int(b) % group > 0):
    days += 1

print(days)
