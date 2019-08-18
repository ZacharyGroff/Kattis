#include <iostream>
#include <set>
#include <vector>

int main() {
  int num_people, num_trees, person, tree;
  std::cin >> num_people >> num_trees;

  std::vector<std::set<int>> opinions(num_people);
  while (std::cin >> person >> tree) {
    opinions[person - 1].insert(tree);
  }

  std::set<std::set<int>> unique_opinions;
  for (int i = 0; i < num_people; i++) {
    unique_opinions.insert(opinions[i]);
  }

  std::cout << unique_opinions.size() << std::endl;

  return 0;
}
