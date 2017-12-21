import numpy as np

array = np.zeros((4,4))
col = 0
row = 0

for i in range(4):
    tempRow = list(map(int, input().split()))
    for x in tempRow:
        array[col][row] = x
        row += 1
    col += 1
    row = 0

instruction = int(input())

if (instruction == 1 or instruction == 3):
    array = array.transpose()

if (instruction == 0 or instruction == 1):
    for row in array:
        for i in range(3):
            for i in range(3):
                if (int(row[i]) == 0):
                    row[i] += row[i+1]
                    row[i+1] = 0
        for i in range(3):
            if (row[i] == row[i+1]):
                row[i] += row[i+1]
                row[i+1] = 0
        for i in range(3):
            for i in range(3):
                if (int(row[i]) == 0):
                    row[i] += row[i+1]
                    row[i+1] = 0

elif (instruction == 2 or instruction == 3):
    for row in array:
        for i in range(3, 0, -1):
            for i in range(3, 0, -1):
                if (int(row[i]) == 0):
                    row[i] += row[i-1]
                    row[i-1] = 0
        for i in range(3, 0, -1):
            if (row[i] == row[i-1]):
                row[i] += row[i-1]
                row[i-1] = 0
        for i in range(3, 0, -1):
            for i in range(3, 0, -1):
                if (int(row[i]) == 0):
                    row[i] += row[i-1]
                    row[i-1] = 0

if (instruction == 1 or instruction == 3):
    array = array.transpose()

for x in range(4):
    print(int(array[x][0]), int(array[x][1]), int(array[x][2]), int(array[x][3]))
