#include "file.hpp"

void File::sort()
{ //Сортирует файл по убыванию времени
    std::vector<PersonStats> user;
    user = load();

    for (unsigned int i = 0; i < user.size(); i++) {
        for (unsigned int j = 0; j < user.size() - i - 1; j++) {
            if (user[j].time < user[j + 1].time) {
                std::swap(user[j], user[j + 1]);
            }
        }
    }

    std::ofstream file;

    file.open(path, std::ios::trunc);

    for (unsigned int i = 0; i < user.size(); i++) {
        file.write((char*)&user[i], sizeof(PersonStats));
    }

    file.close();
}

void File::add(char name[50], float time)
{ //Добавялет запись о пользователе в конец файала
    PersonStats person;

    for (int i = 0; i < 50; i++)
        person.user_name[i] = name[i];

    person.time = time;

    std::ofstream file;
    file.open(
            path,
            std::ios::binary | std::ios::app); //открываем файл и записываем
    file.write((char*)&person, sizeof(PersonStats)); //информацию в конец файла
    file.close();
    sort();
}

std::vector<PersonStats> File::load()
{ //Загружает информацию о пользователях из файла
    std::vector<PersonStats> users_stat;
    PersonStats buffer;
    std::ifstream file;

    file.open(path, std::ios::binary);

    if (!file.is_open()) {
        std::cout << "Файл не существует" << std::endl;
        file.open(path, std::ios::binary);
    }

    while (file.read((char*)&buffer, sizeof(PersonStats))) {
        users_stat.push_back(buffer);
    }

    file.close();
    return users_stat;
}

int File::find(char key[])
{ //Возвращает номер поизиции элемента в файле
    std::vector<PersonStats> users;
    users = load();

    int left = 0;
    int right = users.size();
    int midd;

    while (left <= right) {
        midd = (left + right) / 2;

        if ((std::string)users[midd].user_name == (std::string)key) {
            return midd;
        }
        if ((std::string)users[midd].user_name < (std::string)key) {
            left = midd + 1;
        } else {
            right = midd - 1;
        }
    }

    std::cout << "Информация о данном пользователе отсутствует" << std::endl;
    return -1;
}

void File::show()
{ //Показываетс содержимое файла
    std::vector<PersonStats> user;
    user = load();

    for (unsigned int i = 0; i < user.size(); i++) {
        std::cout << user[i].user_name << " " << user[i].time << std::endl;
    }
}