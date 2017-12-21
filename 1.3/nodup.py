myList = input().lower().split()
answer = 'yes'

for i in myList:
    if (myList.count(i) > 1):
        answer = 'no'

print(answer)
