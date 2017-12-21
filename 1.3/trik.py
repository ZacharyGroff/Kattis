result = 1
myInput = list(input().lower())

#ugly code
for i in myInput:
    if (i == 'a'):
        if (result == 1):
            result = 2
        elif (result == 2):
            result = 1
    elif (i == 'b'):
        if (result == 3):
            result = 2
        elif (result == 2):
            result = 3
    elif (i == 'c'):
        if (result == 3):
            result = 1
        elif (result == 1):
            result = 3
    else:
        print('improper input: ', i)

print(result)
