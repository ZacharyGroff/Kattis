#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int test_cases;
  std::cin >> test_cases;
  for (int test_case = 1; test_case < test_cases+1; test_case++) {
    int max_letters, keys, letters;
    std::cin >> max_letters >> keys >> letters;

    std::vector<int> frequencies;;
    for (int i = 0; i < letters; i++) {
      int frequency;
      std::cin >> frequency;
      frequencies.push_back(frequency);
    }

    std::sort(frequencies.begin(), frequencies.end());

    long key_presses = 0;
    int iter = 1;
    while (frequencies.size() > 0) {
      for(int i = 0; i < keys; i++) {
        if (frequencies.size() <= 0) {
          break;
        }
        key_presses += (frequencies.back() * iter);
        frequencies.pop_back();
      }
      iter++;
    }

    std::cout << "Case #" << test_case << ": " << key_presses << std::endl;
  }
  return 0;
}
