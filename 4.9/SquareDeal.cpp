#include <iostream>
#include <algorithm>

struct rect {
  int height, width;
};

void reverse(rect* r) {
  int h = r->height;
  r->height = r->width;
  r->width = h;
}

bool can_be_square(rect* rect1, rect* rect2, rect* rect3) {
  int sum_of_height = rect1->height + rect2->height + rect3->height;
  if ((sum_of_height == rect1->width) && (sum_of_height == rect2->width) && (sum_of_height == rect3->width)) {
    return true;
  } else if ((rect1->height == rect2->height + rect3->height) && (rect2->width == rect3->width) && (rect1->height == rect1->width + rect2->width)) {
    return true;
  }

  return false;
}

bool check(rect* rects[]) {
  bool success = false;
  do {
    success = can_be_square(rects[0], rects[1], rects[2]);
    if (success) {
      break;
    }
  } while (std::next_permutation(rects, rects+3));

  return success;
}

int main() {
  rect* rects[3];
  bool success = false;
  for (int i = 0; i < 3; i++) {
    int height, width;
    std::cin >> height >> width;
    rects[i] = new rect{height=height, width=width};
  }

  success = check(rects);
  if (success) {
    std::cout << "YES" << std::endl;
    return 0;  
  }
  for (int i = 0; i < 3; i++) {
    reverse(rects[i]);
  }
  success = check(rects);
  if (success) {
    std::cout << "YES" << std::endl;
    return 0;
  }
  reverse(rects[0]);
  success = check(rects);
  if (success) {
    std::cout << "YES" << std::endl;
    return 0;
  }
  reverse(rects[0]);
  reverse(rects[1]);
  success = check(rects);
  if (success) {
    std::cout << "YES" << std::endl;
    return 0;
  }
  reverse(rects[1]);
  reverse(rects[2]);
  success = check(rects);
  if (success) {
    std::cout << "YES" << std::endl;
    return 0;
  }
  reverse(rects[1]);
  success = check(rects);
  if (success) {
    std::cout << "YES" << std::endl;
    return 0;
  }
  reverse(rects[1]);
  reverse(rects[0]);
  success = check(rects);
  if (success) {
    std::cout << "YES" << std::endl;
    return 0;
  }
  reverse(rects[2]);
  reverse(rects[1]);
  success = check(rects);
  if (success) {
    std::cout << "YES" << std::endl;
    return 0;
  }
  
  std::cout << "NO" << std::endl;
  return 0;
}
