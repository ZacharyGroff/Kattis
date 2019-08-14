#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int length, distance, num_birds;
  std::cin >> length >> distance >> num_birds;
  length -= 12;

  std::vector<int> birds;
  for (int i = 0; i < num_birds; i++) {
    int bird;
    std::cin >> bird;
    birds.push_back(bird-6);
  }
  birds.push_back(length+distance);

  std::sort(birds.begin(), birds.end());

  int additional_birds = 0;
  int i = 0;
  while (i <= length) {
    auto upper = std::upper_bound(birds.begin(), birds.end(), i);
    if (upper == birds.end()) {
      break;
    }
    int next_bird = *upper;
    
    int prev_bird;
    auto lower = std::lower_bound(birds.begin(), birds.end(), next_bird-1);
    if (lower == birds.end() || lower == birds.begin()) {
      prev_bird = 0-distance;
    } else {
      prev_bird = *(--lower);
    }


    if (next_bird - i >= distance && i - prev_bird >= distance) {
      additional_birds++;
    }

    if (i + distance > next_bird) {
      i = next_bird;
    } else {
      i += distance;
    }
  }

  std::cout << additional_birds << std::endl;

  return 0;
}
