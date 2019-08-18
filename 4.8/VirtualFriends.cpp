#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>

class UF {
  int *id, cnt, *sz;

  public:
    UF(int N) {
      cnt = N;
      id = new int[N];
      sz = new int[N];
      for(int i=0; i<N; i++)  {
        id[i] = i;
        sz[i] = 1;
      }
    }

    ~UF() {
      delete [] id;
      delete [] sz;
    }

    int find(int p) {
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
    
    void merge(int x, int y) {
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

    bool connected(int x, int y) {
      return find(x) == find(y);
    }

    int count() {
      return cnt;
    }

    int size(int n) {
      return sz[n];
    }
};

int main() {
  int n;
  scanf("%d\n", &n);

  while (n--) {
    int m;
    scanf("%d\n", &m);
    std::map <std::string, int> map;
    int unique = 0;
    UF ds = UF(m*2);

    while (m--) {
      std::string line;
      std::getline(std::cin, line);
      std::string f1 = line.substr(0, line.find(" "));
      std::string f2 = line.substr(line.find(" ")+1, line.length());

      if (map.find(f1) == map.end()) {
        map[f1] = unique;
        unique++;
      }
      if (map.find(f2) == map.end()) {
        map[f2] = unique;
        unique++;
      }
      ds.merge(map[f1], map[f2]);
      std::cout << ds.size(ds.find(map[f1])) << "\n";
    }
  }

  return 0;
}
