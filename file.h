

#include <string.h>

#include <fstream>
#include <iostream>
#include <vector>

class PersonStats {
 public:
  char name[50];
  float time;
};

class File {
 private:
  std::string path = "lider_board.dat";

 public:
  void add(char name[50],
           float time) {  //добавялет запись о пользователе в конец
    PersonStats person;

    for (int i = 0; i < 50; i++) person.name[i] = name[i];

    person.time = time;

    std::ofstream file;
    file.open(path, std::ios::binary | std::ios::out |
                        std::ios::app);  //открываем файл
    file.write((char *)&person, sizeof(PersonStats));
    file.close();
  }

  std::vector<PersonStats> load() {
    std::vector<PersonStats> vec_per;
    PersonStats perk;
    std::ifstream file2;

    file2.open(path, std::ios::binary | std::ios::in);
    while (file2.read((char *)&perk, sizeof(PersonStats))) {
      // std::cout << perk.name << " " << perk.time << std::endl;
      vec_per.push_back(perk);
    }

    file2.close();
    return vec_per;
  }
};
