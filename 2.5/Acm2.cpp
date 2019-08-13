#include <iostream>
#include <algorithm>

void solve_problem(int problem, int* minutes_remaining, int* time_penalty, int* problems_solved) {
      *minutes_remaining -= problem;
      *time_penalty += 300 - *minutes_remaining;
      (*problems_solved)++;
}

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
    std::cout << problems_solved << " " << time_penalty << std::endl;
    return 0;
  }

  solve_problem(problems[first_index], &minutes_remaining, &time_penalty, &problems_solved);
  problems[first_index] = -1;

  std::sort(problems, problems+num_problems);

  for (int i = 1; i < num_problems; i++) {
    if (minutes_remaining >= problems[i]) {
      solve_problem(problems[i], &minutes_remaining, &time_penalty, &problems_solved);
    }
  }

  std::cout << problems_solved << " " << time_penalty << std::endl;

  return 0;
}
