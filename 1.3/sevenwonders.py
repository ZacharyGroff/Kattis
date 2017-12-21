myList = list(input().upper())

#gross code
print((myList.count('T') ** 2) + (myList.count('C') ** 2) + (myList.count('G') ** 2) + (7 * (min(myList.count('T'), myList.count('C'), myList.count('G')))))
