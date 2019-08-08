#include <iostream>
#include <deque>

int main() {
  int n;
  std::cin >> n;

  std::deque<int> front;
  std::deque<int> back;
  while(n--) {
    std::string command;
    int value;
    std::cin >> command >> value;
    if (command.compare("push_back") == 0) {
      back.push_back(value);
    } else if (command.compare("push_front") == 0) {
      front.push_front(value);
    } else if (command.compare("push_middle") == 0) {
      front.push_back(value);
    } else {
      if (value < front.size()) {
        std::cout << front[value] << std::endl;
      } else {
        std::cout << back[value - front.size()] << std::endl;
      }
    }
  
    int fsize = front.size();
    int bsize = back.size();
    if (fsize > 0 && ((fsize - bsize) > 1)) {
      back.push_front(front.back());
      front.pop_back();
    } else if (bsize > 0 && ((bsize - fsize) > 0)) {
      front.push_back(back.front());
      back.pop_front();
    }
  }

  return 0;
}
