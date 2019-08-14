#include <iostream>
#include <algorithm>

int main() {  
  int total_rooms, filled_rooms;
  std::cin >> total_rooms >> filled_rooms;
  int rooms[total_rooms];
  std::fill_n(rooms, total_rooms, 0);

  for (int i = 0; i < filled_rooms; i++) {
    int room_number;
    std::cin >> room_number;
    rooms[room_number-1] = 1;
  }

  for (int i = 0; i < total_rooms; i++) {
    if (!rooms[i]) {
      std::cout << i+1 << std::endl;
      return 0;
    }
  }
  
  std::cout << "too late" << std::endl;
  
  return 0;
}
