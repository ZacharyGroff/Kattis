n = int(input())

for _ in range(0,n):
    r,e,c = input().split()
    if ((int(e) - int(c)) > int(r)):
        print('advertise')
    elif ((int(e) - int(c)) == int(r)):
        print('does not matter')
    else:
        print('do not advertise')
