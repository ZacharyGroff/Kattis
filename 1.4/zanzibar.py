t = int(input())
answer = 0
for _ in range(t):
    myList = list(map(int, input().split()))
    temp = 1        
    for i in myList[:-1]:
        if (i == 1):
            continue
        elif ((i - (temp*2)) > 0):
            answer += (i - (temp*2))
            temp = i
        else:
            temp = i

    print(answer)
    answer = 0
