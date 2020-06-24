#pragma once

#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

#include "PersonStats.hpp"

class File {
public:
    std::string path = "data/lider_board.dat";
    void sort(); //Сортирует файл по убыванию времени

    //Добавялет запись о пользователе в конец файала
    void
    add(std::string user_name_in,
        std::string text_name_in,
        float time_in,
        float cps_in,
        std::string path = "data/lider_board.dat");

    std::vector<PersonStats> load_of_file(
            std::string path = "data/lider_board.dat"); //Загружает информацию о
                                                        //пользователях из файла

    //Возвращает номер поизиции элемента в файле
    int find(char key[]);

    //Показывает содержимое файла
    void show();
};
