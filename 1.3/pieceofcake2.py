n, h, v = map(int, input().split())
print(max([4 * h * v, 4 * (n-h) * v, 4 * (n-v) * h, 4*(n-v)*(n-h)]))
