import itertools  

def transform(inp, subset):
  for i in subset:
    inp[i-1] += inp[i]
    del(inp[i])
  inp = list(map(int, inp))
  return inp

unique_results = set()
inp = input().split("+")
additions = len(inp)
for i in range(1, additions):
  for subset in itertools.combinations(range(1, additions), i):
    unique_results.add(sum(transform(inp.copy(), subset[::-1])))
unique_results.add(sum(list(map(int, inp))))
print(len(unique_results))
