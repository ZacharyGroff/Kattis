#include <iostream>
#include <math.h>

double get_price(double p, double a, double b, double c, double d, double k) {
  return p * (sin((a * k) + b) + cos((c * k) + d) + 2);
}

int main() {
  double p, a, b, c, d, n;
  std::cin >> p >> a >> b >> c >> d >> n;

  double prices[(int) n];
  for (int i = 1; i < n+1; i++) {
    double price = get_price(p, a, b, c, d, i);
    prices[i-1] = price;
  }

  double max_decline = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      double diff = prices[i] - prices[j];
      if (prices[i] > prices[j]) {
        if (diff > max_decline) {
          max_decline = diff;
        }
      } else {
        break;
      }
    }
  }

  std::printf("%.6f\n", max_decline);
}
