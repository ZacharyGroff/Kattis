#include <iostream>
#include <string>

int main() {
  std::string input;
  std::cin >> input;

  int available_digits[10];
  for (int i = 0; i < 10; i++) {
    available_digits[i] = 0;
  }
  for (char c : input) {
    available_digits[c - 48]++;
  }

  for (int i = 1; i < 10; i++) {
    if (available_digits[i] == 0) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  
  int min_index = 10;
  int min_value = 2147483647;
  for (int i = 1; i < 10; i++) {
    if (min_value > available_digits[i]) {
      min_value = available_digits[i];
      min_index = i;
    }
  }
  
  if (available_digits[min_index] > available_digits[0]) {
    std::cout << 1;
    for (int i = 0; i < available_digits[0]+1; i++) {
      std::cout << 0;
    }
    std::cout << std::endl;
    return 0;
  }

  for (int i = 0; i < available_digits[min_index]+1; i++) {
    std::cout << min_index;
  }
  std::cout << std::endl;
  
  return 0;
}
