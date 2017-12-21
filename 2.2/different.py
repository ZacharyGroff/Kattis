rows = []

while True:
    
    try:
        row = input()
    except EOFError:
        break
    
    if row:
        rows.append(row)
    else:
        break

for row in rows:
    x,y = map(int, row.split())
    print(abs(x-y))
