#include <iostream>
#include <algorithm>
#include <limits>

int main() {
  int n;
  std::cin >> n;

  int balloons[n];
  for (int i = 0; i < n+1; i++) {
    balloons[i] = i+1;
  }

  int helium[n];
  for (int i = 0; i < n; i++) {
    std::cin >> helium[i];
  }

  std::sort(helium, helium+n);
 
  float min = std::numeric_limits<float>::max();
  for (int i = 0; i < n; i++) {
    if (helium[i] > balloons[i]) {
      std::cout << "impossible" << std::endl;
      return 0;
    }
    float percent = ((float) helium[i]) / ((float) balloons[i]);
    if (percent < min) {
      min = percent;
    }
  }

  std::cout << min << std::endl;

  return 0;
}
