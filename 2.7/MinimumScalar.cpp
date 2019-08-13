#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int num_tests;
  std::cin >> num_tests;
  for (int test_num = 1; test_num < num_tests+1; test_num++) {
    int num_coords;
    std::cin >> num_coords;

    std::vector<long> v1;
    for (int i = 0; i < num_coords; i++) {
      long coord;
      std::cin >> coord;
      v1.push_back(coord);
    }

    std::vector<long> v2;
    for (int i = 0; i < num_coords; i++) {
      long coord;
      std::cin >> coord;
      v2.push_back(coord);
    }

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end(), std::greater<long>());

    long product = 0;
    for (int i = 0; i < num_coords; i++) {
      product += v1.back() * v2.back();
      v1.pop_back();
      v2.pop_back();
    }

    std::cout << "Case #" << test_num << ": " << product << std::endl;
  }

  return 0;
}
