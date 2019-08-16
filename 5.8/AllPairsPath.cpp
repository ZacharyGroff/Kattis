#include <stdio.h>
#include <algorithm>
#include <vector>
#include <limits>

#define INFINITY std::numeric_limits<int>::max()

template <typename Mat1, typename Mat2>
auto
shortest_path(Mat1& graph, Mat2& dist, int m) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      dist(i, j) = graph(i, j);
    }
    dist(i, i) = 0;
  }
  
  for (int k = 0; k < m; k++) { 
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
    if (dist(i, k) < INFINITY && dist(k, j) < INFINITY && dist(i, j) > dist(i, k) + dist(k, j)) {
      dist(i, j) = dist(i, k) + dist(k, j);
    }
      }
    }
  }

  for (int k = 0; k < m; k++) { 
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        if (dist(k, k) < 0 && dist(i, k) != INFINITY && dist(k, j) != INFINITY) {
      dist(i, j) = -INFINITY;
    }
      }
    }
  }

  return dist;  
}

template <typename T>
auto
make_array_2d (unsigned m0, unsigned m1)
{
  return [m0, m1, data = std::vector<T>(m0 * m1)]
     (unsigned d0, unsigned d1) mutable -> T&
     {
       return data[d0 * m1 + d1];
     };
};

int main() {
  while (1) {    
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    
    if (!n && !m && !q) {
      break;
    }
    
    auto graph = make_array_2d<int>(n, n);
    auto distances = make_array_2d<int>(n, n);
    std::fill_n(&graph(0, 0), (n) * (n), -INFINITY);
    std::fill_n(&graph(0, 0), (n) * (n), INFINITY);
    
    for (int i = 0; i < m; i++) {
      int source, target, weight;
      scanf("%d %d %d", &source, &target, &weight);
      graph(source, target) = (weight < graph(source, target) ? weight: graph(source, target));
    }
    
    auto _distances = shortest_path(graph, distances, n);

    for (int i = 0; i < q; i++) {
      int source, target;
      scanf("%d %d", &source, &target);
      int shortest = _distances(source, target);
      if (shortest == -INFINITY) {
        printf("-Infinity\n");
      }
      else if (shortest == INFINITY) {
        printf("Impossible\n");
      } else {
    printf("%d\n", shortest);
        }
    }
    printf("\n");
  }
  return 0;
}

