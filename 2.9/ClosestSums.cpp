#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>

std::set<int> get_sums(std::vector<int> numbers) {
  std::set<int> sums;
  for (int i = 0; i < numbers.size(); i++) {
    for (int j = i+1; j < numbers.size(); j++) {
      sums.insert(numbers[i]+numbers[j]);
    }
  }

  return sums;
}

int main() {
  int case_number = 0;
  int n;
  while (std::cin >> n) {
    std::cout << "Case " << ++case_number << ":" << std::endl;
    std::vector<int> numbers;
    while(n--) {
      int number;
      std::cin >> number;
      numbers.push_back(number);
    }
    std::set<int> sums = get_sums(numbers);
    int m;
    std::cin >> m;
    while(m--) {
      int query;
      std::cin >> query;
      int upper_bound = sums.upper_bound(query) == sums.begin() ? *--sums.end() : *--sums.upper_bound(query);
      int lower_bound = *sums.lower_bound(query);
      int closest = abs(query - upper_bound) < abs(query - lower_bound) ? upper_bound : lower_bound;
      std::cout << "Closest sum to " << query << " is " << closest << "." << std::endl;
    }
  }
  
  return 0;
}
