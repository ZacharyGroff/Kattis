from math import sqrt
n, w, h = input().split()

for _ in range (0,int(n)):
    if (int(input()) <= (sqrt(int(w) ** 2 + int(h) ** 2))):
        print('DA')
    else:
        print('NE')
        
