#include <iostream>
#include <algorithm>

int main() {
  int heights[6];
  int tower1, tower2;

  for (int i = 0; i < 6; i++) {
    std::cin >> heights[i];
  }

  std::cin >> tower1 >> tower2;

  do {
    int i = 0, sum1 = 0, sum2 = 0;
    for (; i < 3; i++) {
      sum1 += heights[i];
    }
    for (; i < 6; i++) {
      sum2 += heights[i];
    }
    if ((sum1 == tower1) && (sum2 == tower2)) {
      std::sort(heights, heights+3, std::greater<int>());
      std::sort(heights+3, heights+6, std::greater<int>());
    
      for (int i = 0; i < 5; i++) {
        std::cout << heights[i] << " ";
      }
      std::cout << heights[5] << std::endl;
      break;
    }
    if ((sum1 == tower2) && (sum2 == tower1)) {
      std::sort(heights, heights+3, std::greater<int>());
      std::sort(heights+3, heights+6, std::greater<int>());
    
      for (int i = 3; i < 6; i++) {
        std::cout << heights[i] << " ";
      }
      for (int i = 0; i < 2; i++){
        std::cout << heights[i] << " ";
      }
      std::cout << heights[2] << std::endl;
      break;
    }
  } while(std::next_permutation(heights, heights+6));

  return 0;
}
