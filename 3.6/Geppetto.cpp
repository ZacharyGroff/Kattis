#include <iostream>
#include <set>
#include <cmath>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::set<std::pair<int, int>> restrictions;
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    restrictions.insert(std::make_pair(x, y));
  }

  std::set<std::set<int>> subsets;
  for (int i = 0; i < std::pow(2, n); i++) {
    std::set<int> subset;
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) != 0) {
        subset.insert(j+1);
      }
    }
    if (subset.size() > 0) {
      subsets.insert(subset);
    } 
  }

  int count = 0;
  for (auto subset : subsets) {
    bool valid = true;
    for (auto restriction : restrictions) {
      if (subset.find(restriction.first) != subset.end() && subset.find(restriction.second) != subset.end()) {
        valid = false;
        break;
      }
    }
    if (valid) {
      count++;
    }
  }
  
  std::cout << count+1 << std::endl;
}
