crypt = input().upper()
days = 0
count = 0

for i in crypt:
    if (count == 3):
        count = 0
    count += 1

    if ((count == 1 and i is not 'P') or (count == 2 and i is not 'E') or (count == 3 and i is not 'R')):
        days += 1

print(days)
