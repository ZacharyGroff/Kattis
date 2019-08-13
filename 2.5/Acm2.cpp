#include <iostream>
#include <algorithm>

int main() {
  int num_problems, first_index;
  std::cin >> num_problems >> first_index;

  int problems[num_problems];
  for (int i = 0; i < num_problems; i++) {
    std::cin >> problems[i];
  }

  int minutes_remaining = 300;
  int time_penalty = 0;
  int problems_solved = 0;
  if (problems[first_index] > minutes_remaining) {
    std::cout << "0 0" << std::endl;
    return 0;
  }
  minutes_remaining -= problems[first_index];
  problems[first_index] = -1;
  time_penalty += 300 - minutes_remaining;
  problems_solved++;

  std::sort(problems, problems+num_problems);

  for (int i = 1; i < num_problems; i++) {
    if (minutes_remaining >= problems[i]) {
      minutes_remaining -= problems[i];
      time_penalty += 300 - minutes_remaining;
      problems_solved++;
    }
  }

  std::cout << problems_solved << " " << time_penalty << std::endl;

  return 0;
}
