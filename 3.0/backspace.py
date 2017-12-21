myString = input()
loc = 0
output = [''] * len(myString)

for i in myString:
    if (i == '<'):
        loc -= 1
        output[loc] = ''
    else:
        output[loc] = i
        loc += 1
print(''.join(output))
