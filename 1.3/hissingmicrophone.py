inputString = input() + 'e'
answer = 'no hiss'

for i in range(len(inputString)):
    if (inputString[i] == 's' and inputString[i+1] == 's'):
        answer = 'hiss'
print(answer)
