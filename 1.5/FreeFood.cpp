#include <iostream>
#include <algorithm>
#include <numeric>

int main() {  
  int num_events;
  std::cin >> num_events;

  int days[365];
  std::fill_n(days, 365, 0);

  while (num_events--) {
    int start, end;
    std::cin >> start >> end;

    for (int i = start; i <= end; i++) {
      days[i-1] = 1;
    }
  }

  int days_serving = std::accumulate(days, days+365, 0);

  std::cout << days_serving << std::endl;
}
