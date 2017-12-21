t = int(input())

for _ in range(0,t):
    n = int(input())
    cityList = []
    for _ in range(0,n):
        city = input()
        if city not in cityList:
            cityList.append(city)
    print(len(cityList))
