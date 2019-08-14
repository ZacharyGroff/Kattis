#include <iostream>
#include <algorithm>

int main() {
  while (1) {
    int num_ops;
    std::cin >> num_ops;
    if (num_ops == 0) {
      return 0;
    }

    int bits[32];
    std::fill_n(bits, 32, -1);
    for (int i = 0; i < num_ops; i++) {
      std::string op;
      std::cin >> op;
      if (op.compare("CLEAR") == 0) {
        int bit;
        std::cin >> bit;
        bits[bit] = 0;
      } else if (op.compare("SET") == 0) {
        int bit;
        std::cin >> bit;
        bits[bit] = 1;
      } else if (op.compare("OR") == 0) {
        int bit1, bit2;
        std::cin >> bit1 >> bit2;
        if (bits[bit1] != -1 && bits[bit2] != -1) {
          bits[bit1] |= bits[bit2];
        } else if (bits[bit1] == 1 || bits[bit2] == 1){
          bits[bit1] = 1;
        } else {
          bits[bit1] = -1;
        }
      } else if (op.compare("AND") == 0) {
        int bit1, bit2;
        std::cin >> bit1 >> bit2;
        if (bits[bit1] != -1 && bits[bit2] != -1) {
          bits[bit1] &= bits[bit2];
        } else if (bits[bit1] == 0 || bits[bit2] == 0) {
          bits[bit1] = 0;
        } else {
          bits[bit1] = -1;
        }
      }
    }
    
    for (int j = 31; j >= 0; j--) {
      if (bits[j] == -1) {
        std::cout << "?";
      } else {
        std::cout << bits[j];
      }
    }
    std::cout << std::endl;
  }
}
