gunnar = map(int, input().split())
emma = map(int, input().split())

emma = sum(emma)
gunnar = sum(gunnar)

if (emma > gunnar):
    print('Emma')
elif (emma < gunnar):
    print('Gunnar')
else:
    print('Tie')
