#include <iostream>
#include <bitset>
#include <iostream>
#include <cstring>
#include <algorithm>

#define N 100000010
std::bitset<N> primes;

int main() {
  int n, q;
  std::cin >> n;
  std::cin >> q;

  primes.flip();
  primes[1] = 0;

  for (int i = 2; i*i <= n; i++) {
    if (primes[i]) {
        for (int j = i*2; j <= n; j += i) {
          primes[j] = 0;
        }
    }
  }

  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (primes[i]) {
      count++;
    }
  }
  
  std::cout << count << "\n";
  
  while(q--) {
    int query;
    std::cin >> query;
    if (primes[query]) {
      std::cout << "1" << "\n";
    } else {
      std::cout << "0" << "\n";
    }
  }

  return 0;
}
