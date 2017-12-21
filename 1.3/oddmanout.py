n = int(input())

for x in range (1,n + 1):
    uselessInt = input()
    myList = input().split()
    for i in myList:
        if (myList.count(i) != 2):
            print('Case #%d: %d' % (int(x),int(i)))
