#include <iostream>
#include <algorithm>

int main() {
  int solar_systems, total_ships;
  std::cin >> solar_systems >> total_ships;

  int ships[solar_systems];
  for (int i = 0; i < solar_systems; i++) {
    std::cin >> ships[i];
  }

  std::sort(ships, ships+solar_systems);

  int battles_won = 0;
  for (int i = 0; i < solar_systems; i++) {
    if (total_ships > ships[i]) {
      battles_won++;
      total_ships -= ships[i]+1;
    } else {
      break;
    }
  }

  std::cout << battles_won << std::endl;

  return 0;
}
