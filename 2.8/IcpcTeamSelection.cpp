#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int num_tests;
  std::cin >> num_tests;
  while(num_tests--) {
    int num_teams;
    std::cin >> num_teams;
    int num_players = num_teams*3;

    std::vector<int> players;
    for (int i = 0; i < num_players; i++) {
      int player;
      std::cin >> player;
      players.push_back(player);
    }

    std::sort(players.begin(), players.end());

    int max_score = 0;
    for (int i = 0; i < num_teams; i++) {
      players.pop_back();
      max_score += players.back();
      players.pop_back();     
    }
    
    std::cout << max_score << std::endl;
  }

  return 0;
}
