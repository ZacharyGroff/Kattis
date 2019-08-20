#include <iostream>
#include <algorithm>

int main() {
  int num_tests;
  std::cin >> num_tests;

  for (int test_num = 1; test_num < num_tests+1; test_num++) {
    int num_snappers, num_snaps;
    std::cin >> num_snappers >> num_snaps;

    int snappers[num_snappers];
    std::fill_n(snappers, num_snappers, 0);
    for (int snaps = 0; snaps < num_snaps; snaps++) {
      for (int i = 0; i < num_snappers; i++) {
        if (!snappers[i]) {
          snappers[i] = !snappers[i];
          break;
        }
        snappers[i] = !snappers[i];
      }
    }
    std::string state = "ON";
    for (int i = 0; i < num_snappers; i++) {
      if (!snappers[i]) {
        state = "OFF";
        break;
      }
    }
    std::cout << "Case #" << test_num << ": " << state << std::endl;
  }
}
