#include <iostream>
#include <algorithm>
#include <numeric>

int main() {  
  int num_obstacles, num_found_obstacles;
  std::cin >> num_obstacles >> num_found_obstacles;

  int obstacles[num_obstacles];
  std::fill_n(obstacles, num_obstacles, 0);

  for (int i = 0; i < num_found_obstacles; i++) {
    int obstacle;
    std::cin >> obstacle;
    obstacles[obstacle] = 1;
  }

  for (int i = 0; i < num_obstacles; i++) {
    if (!obstacles[i]) {
      std::cout << i << std::endl;
    }
  }

  int found_obstacles = std::accumulate(obstacles, obstacles+num_obstacles, 0);

  std::cout << "Mario got " << found_obstacles << " of the dangerous obstacles." << std::endl;
}
