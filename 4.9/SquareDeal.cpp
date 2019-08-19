#include <iostream>
#include <algorithm>

struct rect {
  int height, width;
};

bool can_be_square(int h1, int h2, int h3, int w1, int w2, int w3) {
  int sum_of_height = h1 + h2 + h3;
  if ((sum_of_height == w1) && w1 == w2 && w2 == w3) {
    return true;
  } else if ((h1 == h2 + h3) && (w2 == w3) && (h1 == w1 + w2)) {
    return true;
  }

  return false;
}

bool check(rect* rects[]) {
  bool success = false;
  do {
    success = can_be_square(rects[0]->height, rects[1]->height, rects[2]->height, rects[0]->width, rects[1]->width, rects[2]->width);
    if (success) {
      break;
    }
  } while (std::next_permutation(rects, rects+6));

  return success;
}

int main() {
  rect* rects[6];
  for (int i = 0; i < 3; i++) {
    int height, width;
    std::cin >> height >> width;
    rects[i] = new rect{height, width};
    rects[i+3] = new rect{width, height};
  }

  bool success = check(rects);

  std::cout << (success ? "YES" : "NO") << std::endl;

  return 0;
}
