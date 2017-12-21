n,m = map(int, input().split())
possibilities = []
answer = []
boolVar = True

for x in range(1,n+1):
    for y in range(1,m+1):
        possibilities.append(x+y)

for x in possibilities:
    for y in possibilities:
        if (possibilities.count(x) < possibilities.count(y)):
            boolVar = False
            break
    if (boolVar == True and x not in answer):
        answer.append(x)
    boolVar = True
        
for i in answer:
    print(i)
