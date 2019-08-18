#include <iostream>
#include <stdio.h>

class UnionFind {
private:
  int *ids, count, *set_sizes;
public:
  UnionFind(int n);
  int find_root(int p);
  void _union(int x, int y);
  bool are_connected(int x, int y);
};

UnionFind::UnionFind(int n) {
  count = n;
  ids = new int[n];
  set_sizes = new int[n];
  for(int i = 0; i < n; i++)  {
    ids[i] = i;
    set_sizes[i] = 1;
  }
}

int UnionFind::find_root(int p) {
  int root = p;
  while (root != ids[root]) {
      root = ids[root];
  }
  return root;
}

void UnionFind::_union(int x, int y) {
  int root1 = find_root(x);
  int root2 = find_root(y);
  if (root1 == root2) {
    return;
  }
  
  if (set_sizes[root1] < set_sizes[root2]) { 
    ids[root1] = root2; 
    set_sizes[root2] += set_sizes[root1]; 
  } else { 
    ids[root2] = root1; 
    set_sizes[root1] += set_sizes[root2]; 
  }
}

bool UnionFind::are_connected(int x, int y) {
  return find_root(x) == find_root(y);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int num_elements, num_operations;
  std::scanf("%d %d\n", &num_elements, &num_operations);

  UnionFind ds = UnionFind(num_elements);
  char op;
  int a, b;
  bool are_connected;
  while (num_operations--) {
    std::scanf("%c %d %d\n", &op, &a, &b);
    if (op == '=') {
      ds._union(a, b);
    } else {
      are_connected = ds.are_connected(a, b);
      std::printf("%s\n",(are_connected ? "yes" : "no"));
    }
  }

  return 0;
}
