#include <iostream>
#include <vector>

void print_recursive(int curr, std::vector<std::string> &words, std::vector<std::vector<int>> &strings) {
  std::cout << words[curr];
  for (auto i : strings[curr]) {
    print_recursive(i, words, strings);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  std::cin >> n;
  
  std::vector<std::string> words;
  for(int i = 0; i < n; i++) {
    std::string word;
    std::cin >> word;
    words.push_back(word);
  }

  int first, second;
  std::vector<std::vector<int>> strings;
  strings.assign(n+1, std::vector<int>());

  while(--n) {
    std::cin >> first >> second;
    strings[first - 1].push_back(second - 1);
  }

  print_recursive(first - 1, words, strings);

  return 0;
}
