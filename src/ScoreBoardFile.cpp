#include "ScoreBoardFile.hpp"

//Сортирует файл по убыванию времени
void ScoreBoardFile::sort()
{
    std::vector<PersonStats> users;
    users = load_of_file();

    unsigned long long int time1, time2;

    for (size_t i = 0; i < users.size(); i++) {
        for (size_t j = 0; j < users.size() - i - 1; j++) {
            time1 = ((users[j].time_min * 60000) * 1000)
                    + (users[j].time_sec * 1000) + users[j].time_ms;

            time2 = ((users[j + 1].time_min * 60000) * 1000)
                    + (users[j + 1].time_sec * 1000) + users[j + 1].time_ms;
            if (time1 > time2) {
                std::swap(users[j], users[j + 1]);
            }
        }

        std::ofstream file;

        file.open(path, std::ios::trunc);

        for (auto user : users) {
            file.write((char*)&user, sizeof(PersonStats));
        }

        file.close();
    }
}

//Добавялет запись о пользователе в конец файала
void ScoreBoardFile::add(
        std::string user_name_in,
        std::string text_name_in,
        int time_ms_in,
        int time_sec_in,
        int time_min_in,
        int max_cps_in,
        std::string path)
{
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

//Загружает информацию о пользователях из файла
std::vector<PersonStats> ScoreBoardFile::load_of_file(std::string path)
{
    std::vector<PersonStats> users_stat;
    PersonStats buffer;
    std::ifstream file;

    file.open(path, std::ios::binary);

    if (!file.is_open()) {
        file.open(path, std::ios::binary);
    }

    while (file.read((char*)&buffer, sizeof(PersonStats))) {
        users_stat.push_back(buffer);
    }

    file.close();
    return users_stat;
}

//Возвращает номер поизиции элемента в файле
int ScoreBoardFile::find(char key[])
{
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

    return -1;
}
