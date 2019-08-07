stack = []
while 1:
    try:
        [stack.append(i) for i in input().split()]
    except(EOFError):
        break
sorted = set()
while len(stack) > 0:
    word = stack.pop()
    for i in stack:
        sorted.add(word+i)
        sorted.add(i+word)
sorted = list(sorted)
sorted.sort()
[print(i) for i in sorted]
