#pragma once

#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

class PersonStats {
public:
    char user_name[50];
    char text_name[50];
    float time;
    float cps;
};

class File {
private:
    std::string path = "data/lider_board.dat";

public:
    void sort(); //Сортирует файл по убыванию времени

    void
    add(char name[50],
        float time); //Добавялет запись о пользователе в конец файала

    std::vector<PersonStats>
    load(); //Загружает информацию о пользователях из файла

    int find(char key[]); //Возвращает номер поизиции элемента в файле

    void show(); //Показывает содержимое файла
};
