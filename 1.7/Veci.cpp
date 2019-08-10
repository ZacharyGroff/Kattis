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

int main() {
  std::string number;
  std::cin >> number;
  int end = number.size() - 1;
  
  std::set<std::string> permutations;
  get_permutations(permutations, number, 0, end);
  
  auto it = permutations.lower_bound(number);
  std::cout << (it == --permutations.end() ? "0" : *++it) << std::endl;
}
