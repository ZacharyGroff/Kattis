#include <iostream>

const char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};

bool is_vowel(char c) {
  for (int i = 0; i < 6; i++) {
    if (c == vowels[i]) {
      return true;
    }
  }
  return false;
}

int get_pairs(std::string word) {
  int pairs = 0;
  for (int i = 0; i < word.length()-1; i++) {
    if (is_vowel(word[i]) && word[i] == word[i+1]) {
        pairs++;
    }
  }

  return pairs;
}

int main() {
  while (1) {
    int words;
    std::cin >> words;

    if (words == 0) {
      return 0;
    }

    std::string favorite;
    int most_seen = -1;
    for (int i = 0; i < words; i++) {
      std::string current_word;
      std::cin >> current_word;
      int pairs = get_pairs(current_word);
      if (pairs > most_seen) {
        favorite = current_word;
        most_seen = pairs;
      }
    }
    std::cout << favorite << std::endl;
  }
}
