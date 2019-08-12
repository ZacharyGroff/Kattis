#include <iostream>
#include <set>
#include <cmath>
#include <cstdlib>

int get_total_sb(int subset, int n, std::pair<int, int> sbs[]) {
  int sourness = 1;
  int bitterness = 0;
  for (int i = 0; i < n; i++) {
    if ((subset & (1 << i)) != 0) {
      sourness *= sbs[i].first;
      bitterness += sbs[i].second;
    }
  }
  return abs(sourness - bitterness);
}

int main() {
  int n;
  std::cin >> n;

  std::pair<int, int> ratings[n];
  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    ratings[i] = std::make_pair(x, y);
  }
  
  int min_sb = 2147483647;
  for (int i = 1; i < std::pow(2, n); i++) {
    int sb = get_total_sb(i, n, ratings);
    if (min_sb > sb) {
      min_sb = sb;
    }
  }

  std::cout << min_sb << std::endl;

  return 0;
}
