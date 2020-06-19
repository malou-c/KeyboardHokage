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
    void sort(); //Сортирует файл по убыванию времени

    void
    add(char user_name_in[50],
        char text_name_in[50],
        float time_in,
        float cps_in,
        std::string path
        = "data/lider_board.dat"); //Добавялет запись о пользователе в
                                   //конец файала

    std::vector<PersonStats>
    load(std::string path = "data/lider_board.dat"); //Загружает информацию о
                                                     //пользователях из файла

    int find(char key[]); //Возвращает номер поизиции элемента в файле

    void show(); //Показывает содержимое файла
};
