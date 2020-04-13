#pragma once

#include <fstream>
#include <string.h>
#include <vector>

typedef struct List {
  char name[20];
  float time;

  struct List *next;
} List;

struct PersonStats {
  std::vector<std::string> name;
  std::vector<float> time;
};

class File {
private:
  std::string path = "lider board.dat";

public:

  void add(std::string name, float time) { //добавялет запись о пользователе в конец
    PersonStats person;
    int person_size;

    std::fstream file;
    std::ofstream w_file;

    file.open(path, std::ios::binary | std::ios::in | std::ios::out);//открываем файл

    if (!file.is_open()) {//если не получилось найти файл то создаем его

      std::ofstream create;
      create.open(path, std::ios::binary);
      create.close();

      file.open(path, std::ios::binary | std::ios::in | std::ios::out);

      if (!file.is_open()) {
        std::cout << "Не получается создать файл" << std::endl;
        return;
      }
    }

    if (file.read((char *)&person_size, sizeof(int))){//если файл не пустой
      std::cout << person_size;
      file.read((char *)&person, person_size);
      file.close();
      w_file.open(path, std::ios::binary);
      person.name.push_back(name);
      person.time.push_back(time);

      person_size = sizeof(person);

      w_file.write((char *)&person_size, sizeof(int));
      w_file.write((char *)&person, person_size);
      w_file.close();
    } else {//если файл пустой
      file.close();
      w_file.open(path, std::ios::binary);
      person.name.push_back(name);
      person.time.push_back(time);

      person_size = sizeof(person);
      //std::cout << person_size;

      w_file.write((char *)&person_size, sizeof(int));
      w_file.write((char *)&person, sizeof(person));
      w_file.close();
    }

  }

/*  PersonStats load() {
    PersonStats persons;

    std::ifstream file;

    file.open(path, std::ios::binary);

    if (!file.is_open()) {
      std::cout << "Файл не найден" << std::endl;
    } else {

      file.read((char *)&persons, sizeof(PersonStats));
      file.close();

      std::cout << persons.name[0] << " " << persons.name[1];

      return persons;
    }


  }*/
};
