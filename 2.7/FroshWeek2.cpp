#include <iostream>
#include <algorithm>
#include <deque>

int main() {
  int num_tasks, num_intervals;
  std::cin >> num_tasks >> num_intervals;

  std::deque<int> tasks;
  for (int i = 0; i < num_tasks; i++) 
  {
    int task;
    std::cin >> task;
    tasks.push_back(task);
  }

  std::deque<int> intervals;
  for (int i = 0; i < num_intervals; i++) 
  {
    int interval;
    std::cin >> interval;
    intervals.push_back(interval);
  }

  std::sort(tasks.begin(), tasks.end());
  std::sort(intervals.begin(), intervals.end());

  int tasks_completed = 0;
  while (intervals.size() > 0 && tasks.size() > 0){
    if (intervals[0] >= tasks[0]) {
      tasks_completed++;
      tasks.pop_front();
    }
    intervals.pop_front();
  }

  std::cout << tasks_completed << std::endl;

  return 0;
}
