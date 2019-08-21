def print_test_case(words, current_word):
  if current_word in words:
    print(words[current_word])
  else:
    print(0)

def update_word_dict(words, current_word):
  for i in range(1, len(current_word)+1):
    substring = current_word[:i]
    if substring not in words:
      words[substring] = 0   
    words[substring] += 1
  return words

def main():
  num_words = int(input())
  words = dict()
  for _ in range(num_words):
    current_word = input()
    print_test_case(words, current_word)
    words = update_word_dict(words, current_word)

if __name__ == '__main__':
  main()
