#include <iostream>

long long length, ops;
long long ftree[5000001];

long long sum(int index) { 
    long long sum = 0;
    index++; 
    while (index > 0) 
    { 
        sum += ftree[index]; 
  
        index -= index & (-index); 
    } 
    return sum; 
} 
  
void update(int index, int val) { 
    index++; 
    while (index < length+1) 
    { 
      ftree[index] += val; 
    
      index += index & (-index); 
    } 
} 
  
int main() { 
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::scanf("%lld%lld\n", &length, &ops);
  std::fill_n(ftree, length+1, 0);

  long long index, value;
  char op;
  for (int i = 0; i < ops; i++) {
    std::scanf("%c", &op);
    if (op == '+') {
      std::scanf("%lld%lld\n", &index, &value);
      update(index, value);
    } else {
      std::scanf("%lld\n" , &index);
      std::printf("%lld\n", sum(index-1));
    }
  }
}
