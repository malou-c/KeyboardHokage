#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>

class PersonStats
{
public:
  char name[50];
  float time;
};

class File
{
private:
  std::string path = "lider_board.dat";

public:
  void sort()
  { //Сортирует файл по убыванию времени
    std::vector<PersonStats> user;
    user = load();

    for (int i = 0; i < user.size(); i++)
    {
      for (int j = 0; j < user.size() - i - 1; j++)
      {
        if (user[j].time < user[j + 1].time)
        {
          std::swap(user[j], user[j + 1]);
        }
      }
    }

    std::ofstream file;

    file.open(path, std::ios::trunc);

    for (int i = 0; i < user.size(); i++)
    {
      file.write((char *)&user[i], sizeof(PersonStats));
    }

    file.close();
  }

  void add(char name[50],
           float time)
  { //Добавялет запись о пользователе в конец файала
    PersonStats person;

    for (int i = 0; i < 50; i++)
      person.name[i] = name[i];

    person.time = time;

    std::ofstream file;
    file.open(path, std::ios::binary | std::ios::app); //открываем файл и записываем
    file.write((char *)&person, sizeof(PersonStats));  //информацию в конец файла
    file.close();
  }

  std::vector<PersonStats> load()
  { //Загружает информацию о польхователях из файла
    std::vector<PersonStats> users_stat;
    PersonStats buffer;
    std::ifstream file;

    file.open(path, std::ios::binary);

    if (!file.is_open())
    {

      std::cout << "Файл не существует" << std::endl;
    }

    while (file.read((char *)&buffer, sizeof(PersonStats)))
    {
      users_stat.push_back(buffer);
    }

    file.close();
    return users_stat;
  }

  int find(char key[])
  { //Возвращает номер поизиции элемента в файле
    std::vector<PersonStats> users;
    users = load();

    int left = 0;
    int right = users.size();
    int midd;

    while (left <= right)
    {
      midd = (left + right) / 2;

      if ((std::string)users[midd].name == (std::string)key)
      {
        return midd;
      }
      if ((std::string)users[midd].name < (std::string)key)
      {
        left = midd + 1;
      }
      else
      {
        right = midd - 1;
      }
    }

    std::cout << "Информация о данном пользователе отсутствует" << std::endl;
    return -1;
  }

  void show()
  {
    std::vector<PersonStats> user;
    user = load();

    for (int i = 0; i < user.size(); i++)
    {
      std::cout << user[i].name << " " << user[i].time << std::endl;
    }
  }
};
