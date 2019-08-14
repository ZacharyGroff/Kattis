#include <iostream>
#include <algorithm>
#include <numeric>

int main() {
  int test_cases;
  std::cin >> test_cases;
  while (test_cases--) {
    int customers;
    std::cin >> customers;

    long long customer_times[customers];
    for (int customer = 0; customer < customers; customer++) {
      int num_logs;
      std::cin >> num_logs;

      long long total_time = 0;
      for (int i = 0; i < num_logs; i++) {
        int log;
        std::cin >> log;
        total_time += log;
      }
      customer_times[customer] = total_time;
    }

    std::sort(customer_times, customer_times+customers);

    long total_waiting_time = 0;
    long current_time = 0;
    for (int i = 0; i < customers; i++) {
      current_time += customer_times[i];
      total_waiting_time += current_time; 
    }

    long double average_waiting_time = ((long double) total_waiting_time / (long double) customers);

    std::printf("%.9Lf\n", average_waiting_time);
  }

  return 0;
}
