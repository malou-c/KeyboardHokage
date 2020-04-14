#include <iostream>

#include "file.h"

int main() {
  File test;
  char name[50] = "Voava";
  test.add(name, 213811);
  test.add(name, 21382);

  std::vector<PersonStats> vec = test.load();
  for (int i = 0; i < (int)vec.size(); i++) {
    std::cout << vec[i].name << " " << vec[i].time << std::endl;
  }

  return 0;
}
