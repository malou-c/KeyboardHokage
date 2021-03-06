#pragma once

#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

#include "PersonStats.hpp"

class ScoreBoardFile {
private:
    std::string path = "data/lider_board.dat";

public:
    void sort(); //Сортирует файл по убыванию времени

    //Добавялет запись о пользователе в конец файала
    void
    add(std::string user_name_in,
        std::string text_name_in,
        int time_ms_in,
        int time_sec_in,
        int time_min_in,
        int max_cps_in,
        std::string path = "data/lider_board.dat");

    std::vector<PersonStats> load_of_file(
            std::string path = "data/lider_board.dat"); //Загружает информацию о
                                                        //пользователях из файла
};
