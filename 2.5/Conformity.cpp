#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

int main() {
  int n;
  std::cin >> n;

  std::unordered_map<std::string, int> umap;
  for (int i = 0; i < n; i++) {
    std::vector<std::string> courses;
    for (int j = 0; j < 5; j++) {
      std::string course;
      std::cin >> course;
      courses.push_back(course);
    }
    
    std::sort(courses.begin(), courses.end());
    
    std::string course;
    for (auto i : courses) {
      course += i;
    }

    umap[course]++;
  }

  int largest = 0;
  for (auto it : umap) {
    largest = std::max(largest, it.second);
  }

  int largest_count = 0;
  for(auto it : umap) {
    if (it.second == largest) {
      largest_count += it.second;
    }
  }

  std::cout << largest_count << ::std::endl;

  return 0;
}
