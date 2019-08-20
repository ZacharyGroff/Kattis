#include <iostream>
#include <set>

int main() {
  int num_words;
  std::cin >> num_words;

  std::set<std::string> words_used;
  std::string word;
  char prev_end;
  
  std::string result = "Fair Game";
  for (int i = 0; i < num_words; i++) {
    std::cin >> word;
    if (word[0] != prev_end && i > 0) {
      result = (i % 2 == 0 ? "Player 1 lost" : "Player 2 lost");
      break;
    } else if (words_used.find(word) != words_used.end()) {
      result = (i % 2 == 0 ? "Player 1 lost" : "Player 2 lost");
      break;
    }
    words_used.insert(word);
    prev_end = word[word.length()-1];
  }

  std::cout << result << std::endl;
}
