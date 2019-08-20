#include <iostream>

int main() {
  int num_tests;
  std::cin >> num_tests;

  while(num_tests--) {
    int query;
    std::cin >> query;
    int max_bits = 0;
    while (query > 0) {
      int bits = __builtin_popcount(query);
      if (bits > max_bits) {
        max_bits = bits;
      }
      query /= 10;
    }
    std::cout << max_bits << std::endl;
  }
}
