#include "UnionFind.h"

UnionFind::UnionFind(int n) {
  count = n;
  ids = new int[n];
  set_sizes = new int[n];
  for(int i = 0; i < n; i++)  {
    ids[i] = i;
    set_sizes[i] = 1;
  }
}

UnionFind::~UnionFind() {
  delete [] ids;
  delete [] set_sizes;
}

int UnionFind::find_root(int p) {
  int root = p;
  while (root != ids[root]) {
      root = ids[root];
  }
  while (p != root) {
    int newp = ids[p];
    ids[p] = root;
    p = newp;
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

  count--;
}

bool UnionFind::are_connected(int x, int y) {
  return find_root(x) == find_root(y);
}

int UnionFind::set_count() {
  return count;
}

int UnionFind::size_of_set(int n) {
  return set_sizes[n];
}
