for _ in range(int(input())):
    int(input())
    locations = list(map(int, input().split()))
    print((max(locations) - min(locations)) * 2)
