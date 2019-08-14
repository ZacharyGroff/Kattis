#include <iostream>
#include <algorithm>

int main() {
  int num_items;
  std::cin >> num_items;

  int items[num_items];
  for (int i = 0; i < num_items; i++) {
    std::cin >> items[i];
  }

  std::sort(items, items+num_items);

  long discount = 0;
  for (int item = num_items-3; item >= 0; item-=3) {
    discount += items[item];
  }

  std::cout << discount << std::endl;

  return 0;
}
