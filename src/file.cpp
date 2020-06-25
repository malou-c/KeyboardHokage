#include "file.hpp"

void File::sort()
{ //Сортирует файл по убыванию времени
    std::vector<PersonStats> users;
    users = load_of_file();

    for (size_t i = 0; i < users.size(); i++) {
        for (size_t j = 0; j < users.size() - i - 1; j++) {
            if (users[j].time_min < users[j + 1].time_min) {
                std::swap(users[j], users[j + 1]);
            } else if (users[j].time_sec < users[j + 1].time_sec) {
                std::swap(users[j], users[j + 1]);
            } else if (users[j].time_ms < users[j + 1].time_ms) {
                std::swap(users[j], users[j + 1]);
            }
        }
    }

    std::ofstream file;

    file.open(path, std::ios::trunc);

    for (auto user : users) {
        file.write((char*)&user, sizeof(PersonStats));
    }

    file.close();
}

void File::add(
        std::string user_name_in,
        std::string text_name_in,
        int time_ms_in,
        int time_sec_in,
        int time_min_in,
        int max_cps_in,
        std::string path)
{ //Добавялет запись о пользователе в конец файала
    PersonStats person;

    for (int i = 0; i < 9; i++) {
        person.user_name[i] = user_name_in[i];
    }

    for (int i = 0; i < 50; i++) {
        person.text_name[i] = text_name_in[i];
    }

    person.time_ms = time_ms_in;
    person.time_sec = time_sec_in;
    person.time_min = time_min_in;

    person.max_cps = max_cps_in;

    std::ofstream file;
    file.open(
            path,
            std::ios::binary | std::ios::app); //открываем файл и записываем
    file.write((char*)&person, sizeof(PersonStats)); //информацию в конец файла
    file.close();
    sort();
}

std::vector<PersonStats> File::load_of_file(std::string path)
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
    users = load_of_file();

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
    user = load_of_file();

    for (unsigned int i = 0; i < user.size(); i++) {
        std::cout << user[i].user_name << " " << user[i].time_sec << std::endl;
    }
}