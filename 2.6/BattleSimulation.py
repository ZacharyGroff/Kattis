def main():
  counters = {'R': 'S', 'B': 'K', 'L': 'H'}
  combos = {'RBL', 'RLB', 'BLR', 'BRL', 'LRB', 'LBR'}
  attacks = input()

  skip = 0
  for index, attack in enumerate(attacks):
    if skip:
      skip -= 1
      continue
    if attacks[index:index+3] in combos:
      print('C',end='')
      skip = 2
    else:
      print(counters[attack],end='')
  print()

if __name__ == '__main__':
  main()
