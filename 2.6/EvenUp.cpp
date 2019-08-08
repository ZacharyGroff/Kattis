#include <iostream>
#include <stack>

int main() {
  int n;
  std::cin >> n;

  std::stack<int> cards;
  for(int i = 0; i < n; i++) {
    int card;
    std::cin >> card;
    if ((cards.size() > 0) && (cards.top() + card) % 2 == 0) {
      cards.pop();
    } else {
      cards.push(card);
    }
  }

  std::cout << cards.size() << std::endl;

  return 0;
}
