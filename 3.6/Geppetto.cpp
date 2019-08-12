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
  
  int count = 0;
  bool valid = true;
  for (int i = 0; i < std::pow(2, n); i++) {
    for (auto restriction : restrictions) {
      if (((i&(1 << (restriction.first-1))) != 0) && ((i&(1 << (restriction.second-1))) != 0)) {
        valid = false;
        break;
      }
    }
    if (valid) {
      count++;
    }
    valid = true;
  }
  std::cout << count << std::endl;
}
