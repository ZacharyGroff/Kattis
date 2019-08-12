#include <iostream>
#include <set>
#include <cmath>

bool is_valid(int i, std::set<std::pair<int, int>> &restrictions) {
  for (auto restriction : restrictions) {
    bool contains_first = (i & (1 << (restriction.first-1))) != 0;
    bool contains_second = (i & (1 << (restriction.second-1))) != 0;
    if (contains_first && contains_second) {
      return false;
    }
  }

  return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;

  std::set<std::pair<int, int>> restrictions;
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    restrictions.insert(std::make_pair(x, y));
  }
  
  int count = 0;
  for (int i = 0; i < std::pow(2, n); i++) {
    if (is_valid(i, restrictions)) {
      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
