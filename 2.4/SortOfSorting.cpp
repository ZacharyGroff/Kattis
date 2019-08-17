#include <iostream>
#include <algorithm>

struct iname {
  std::string name;
  int index;
};

bool cmp(iname* n1, iname* n2) {
  if (n1->name[0] != n2->name[0]) {
    return n1->name[0] < n2->name[0];
  } else if (n1->name[1] != n2->name[1]) {
    return n1->name[1] < n2->name[1];
  } else {
    return n1->index < n2->index;
  }
}

int main() {
  while (1) {
    int num_names;
    std::cin >> num_names;

    if (num_names == 0) {
      return 0;
    }

    iname* names[num_names];
    for (int i = 0; i < num_names; i++) {
      std::string name;
      std::cin >> name;
      iname* n  = new iname();
      n->name = name;
      n->index = i;
      names[i] = n;
    }

    std::sort(names, names+num_names, cmp);

    for (int i = 0; i < num_names; i++) {
      std::cout << names[i]->name << std::endl;
    }
    std::cout << std::endl;
  }
}
