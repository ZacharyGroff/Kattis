h, m = input().split()

if ((int(m) - 45) < 0):
    h = int(h) - 1
    if (h == -1):
        h = 23
    m = 60 - abs(int(m) - 45)
else:
    m = int(m) - 45
print(h, m)
