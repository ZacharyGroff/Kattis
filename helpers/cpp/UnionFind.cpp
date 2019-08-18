#include "UnionFind.h"

UnionFind::UnionFind(int n) {
  cnt = n;
  id = new int[n];
  sz = new int[n];
  for(int i = 0; i < n; i++)  {
    id[i] = i;
    sz[i] = 1;
  }
}

UnionFind::~UnionFind() {
  delete [] id;
  delete [] sz;
}

int UnionFind::find(int p) {
  int root = p;
  while (root != id[root]) {
      root = id[root];
  }
  while (p != root) {
    int newp = id[p];
    id[p] = root;
    p = newp;
  }

  return root;
}

void UnionFind::merge(int x, int y) {
  int i = find(x);
  int j = find(y);
  if (i == j) {
    return;
  }

  if (sz[i] < sz[j]) { 
    id[i] = j; 
    sz[j] += sz[i]; 
  } else { 
    id[j] = i; 
    sz[i] += sz[j]; 
  }

  cnt--;
}

bool UnionFind::connected(int x, int y) {
  return find(x) == find(y);
}

int UnionFind::count() {
  return cnt;
}

int UnionFind::size(int n) {
  return sz[n];
}
