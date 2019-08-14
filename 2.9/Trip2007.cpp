#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  while (1) {
    int num_bags;
    std::cin >> num_bags;
    if (num_bags == 0) {
      return 0;
    }

    int bags[num_bags];
    for (int i = 0; i < num_bags; i++) {
      std::cin >> bags[i];
    }

    std::sort(bags, bags+num_bags, std::greater<int>());

    int bags_placed = 0;
    std::vector<std::vector<int>> pieces;
    while (num_bags > bags_placed) {
      int smallest_bag = 2147483647;
      std::vector<int> current_piece;

      for (int i = 0; i < num_bags; i++) {
        if (bags[i] == -1) {
          continue;
        }
        if (smallest_bag > bags[i]) {
          current_piece.push_back(bags[i]);
          smallest_bag = bags[i];
          bags[i] = -1;
          bags_placed++;
        }
      }
  
      pieces.push_back(current_piece);
    }

    std::cout << pieces.size() << std::endl;
    for (auto piece : pieces) {
      for (int i = 0; i < piece.size(); i++) {
        if (i == piece.size()-1) {
          std::cout << piece[i] << std::endl;
        } else {
          std::cout << piece[i] << " ";
        }
      }
    }
  }
}
