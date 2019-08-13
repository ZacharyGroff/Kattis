#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  while (1) {
    int num_heads, num_knights;
    std::cin >> num_heads >> num_knights;

    if (!num_heads && !num_knights) {
      break;
    }

    std::vector<int> heads;
    for (int i = 0; i < num_heads; i++) 
    {
      int head;
      std::cin >> head;
      heads.push_back(head);
    }

    std::vector<int> knights;
    for (int i = 0; i < num_knights; i++) 
    {
      int knight;
      std::cin >> knight;
      knights.push_back(knight);
    }

    std::sort(heads.begin(), heads.end());
    std::sort(knights.begin(), knights.end());

    int gold = 0;
    while (heads.size() > 0 && knights.size() > 0){
      if (knights[0] >= heads[0]) {
        gold += knights[0];
        heads.erase(heads.begin());
      }
      knights.erase(knights.begin());
    }

    if (heads.size() == 0) {
      std::cout << gold << std::endl;
    } else {
      std::cout << "Loowater is doomed!" << std::endl;
    }
  }
  
  return 0;
}
