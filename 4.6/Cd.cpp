#include <iostream>
#include <unordered_set>
#include <stdio.h>

int main() {
  while (1) {
  std::unordered_set <int> jack;
  int n, m, x;
  scanf("%d %d", &n, &m);
  if (n == 0 && m == 0) {
    return 0;
  }
  while (n-- > 0) {
    scanf("%d", &x);
    jack.insert(x);
  }
  int count = 0;
  while (m-- > 0) {
    scanf("%d", &x);
    if (jack.find(x) != jack.end()) {
      count++;
    }
  }
  printf("%d\n", count);
  }
}
