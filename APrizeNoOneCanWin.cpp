#include <iostream>
#include <algorithm>

int main() {
  int num_items, horn_cost;
  std::cin >> num_items >> horn_cost;

  int items[num_items];
  for (int i = 0; i < num_items; i++) {
    std::cin >> items[i];
  }

  std::sort(items, items+num_items);

  int i = 0;
  for (; i < num_items-1; i++) {
    if (items[i] + items[i+1] > horn_cost) {
      break;
    }
  }

  std::cout << i+1 << std::endl;

  return 0;
}
