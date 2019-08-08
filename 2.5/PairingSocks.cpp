#include <iostream>
#include <stack>

int main() {
  int n;
  std::cin >> n;

  std::stack<int> socks, aux_socks;
  for(int i = 0; i < n*2; i++) {
    int sock;
    std::cin >> sock;
    socks.push(sock);
  }

  int moves = 0;
  while (!socks.empty() || !aux_socks.empty()) {
    if (socks.empty() && !aux_socks.empty()) {
        moves = -1;
        break;
    } else if (aux_socks.empty()) {
      aux_socks.push(socks.top());
      socks.pop();
    } else if (socks.top() == aux_socks.top()) {
      socks.pop();
      aux_socks.pop();
    } else {
      aux_socks.push(socks.top());
      socks.pop();
    }

    moves++;
  }

  std::cout << (moves == -1 ? "impossible" : std::to_string(moves)) << std::endl;

  return 0;
}
