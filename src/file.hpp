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

    void
    add(std::string user_name_in,
        std::string text_name_in,
        float time_in,
        float cps_in,
        std::string path
        = "data/lider_board.dat"); //Добавялет запись о пользователе в
                                   //конец файала

    std::vector<PersonStats> load_of_file(
            std::string path = "data/lider_board.dat"); //Загружает информацию о
                                                        //пользователях из файла

    int find(char key[]); //Возвращает номер поизиции элемента в файле

    void show(); //Показывает содержимое файла
};
