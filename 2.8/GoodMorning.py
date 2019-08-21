def get_possible_numbers():
  possible_numbers = set()
  indexes = [(4, 1), (0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2)]

  for i in range(1, 201):
    number = i
    valid = True
    max_x, max_y = 10, 10
    while number > 0:
      digit = number % 10
      x, y = indexes[digit]
      if x > max_x or y > max_y:
        valid = False
        break
      number = int(number / 10)
      max_x, max_y = x, y
    if valid:
      possible_numbers.add(i)
      
  return possible_numbers

def main():
  possible_numbers = get_possible_numbers()
  test_cases = int(input())
  for _ in range(test_cases):
    test_case = int(input())
    result = min(possible_numbers, key=lambda x: abs(x-test_case))
    print(result)

if __name__ == '__main__':
  main()
