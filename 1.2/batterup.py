n = int (input())
s = map (int, input().split())
results = []

for val in s:
    if (val == -1):
        n -= 1
    if (0 < val < 5):
        results.append(val)

print (sum (results) / n)
