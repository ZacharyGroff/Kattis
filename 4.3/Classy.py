def get_pair():
  inp = input().split()
  name = inp[0][:-1]
  rank = inp[1].split('-')[::-1]
  rank = ''.join([c[0] for c in rank])
  return [name, rank]

def get_pairs():
  pairs = []
  num_pairs = int(input())
  for _ in range(num_pairs):
    pair = get_pair()
    pairs.append(pair)
  return pairs

def sort_pairs(pairs):
  max_len = len(max(pairs, key = lambda x: len(x[1]))[1])
  for pair in pairs:
    pair[1] = pair[1] + ('m' * (max_len - len(pair[1])))
  pairs.sort(key=lambda pair: pair[0])
  pairs.sort(key=lambda pair: pair[1], reverse=True)
  return pairs

def print_test_case(pairs):
    for pair in pairs:
        print(pair[0])
    print('='*30)

def main():
  num_tests = int(input())
  for _ in range(num_tests):
    pairs = get_pairs()
    pairs = sort_pairs(pairs)
    print_test_case(pairs)

if __name__ == '__main__':
  main()
