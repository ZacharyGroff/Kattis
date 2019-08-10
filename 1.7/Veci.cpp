#include <iostream>
#include <set>

void get_permutations(std::set<std::string> &permutations, std::string number, int start, int end) {
  if (start == end) {
    permutations.insert(number);
  } else {
    for (int i = start; i <= end; i++) {
      std::swap(number[start], number[i]);
      get_permutations(permutations, number, start+1, end);
      std::swap(number[start], number[i]);
    }
  }
}

std::string get_result(std::string number, std::set<std::string> permutations) {
  auto it = permutations.lower_bound(number);
  return it == --permutations.end() ? "0" : *++it;
}

int main() {
  std::string number;
  std::cin >> number;
  int end = number.size() - 1;

  std::set<std::string> permutations;
  get_permutations(permutations, number, 0, end);
  
  std::string result = get_result(number, permutations);
  std::cout << result << std::endl;
}
