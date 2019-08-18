class UnionFind {
private:
  int *ids, count, *set_sizes;
public:
  UnionFind(int n);
  ~UnionFind();
  int find_root(int p);
  void _union(int x, int y);
  bool are_connected(int x, int y);
  int set_count();
  int size_of_set(int n);
};
