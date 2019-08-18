class UnionFind {
private:
  int *id, cnt, *sz;
public:
  UnionFind(int N);
  ~UnionFind();
  int find(int p);
  void merge(int x, int y);
  bool connected(int x, int y);
  int count();
  int size(int n);
};
