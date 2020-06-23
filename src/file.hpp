#pragma once

#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

#include "PersonStats.hpp"

class File {
private:
    std::string path = "data/lider_board.dat";

public:
    //Сортирует файл по убыванию времени
    void sort();

    //Добавялет запись о пользователе в конец файала
    void
    add(char user_name_in[50],
        char text_name_in[50],
        float time_in,
        float cps_in,
        std::string path = "data/lider_board.dat");

    //Загружает информацию о пользователях из файла
    std::vector<PersonStats> load(std::string path = "data/lider_board.dat");

    //Возвращает номер поизиции элемента в файле
    int find(char key[]);

    //Показывает содержимое файла
    void show();
};
