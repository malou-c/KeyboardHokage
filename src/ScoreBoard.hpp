#pragma once

#include <SFML/Graphics.hpp>

#include "file.hpp"
#include <iostream>

//класс для загрузки таблицы рекордов и ее хранения
class ScoreBoard {
private:
    bool is_loaded = false; //загружена ли таблица рекордов
    std::vector<PersonStats> stats; //для хранения таблицы рекордов

    //загружаем таблицу рекордов из файла
    std::vector<PersonStats> load_board();

public:
    //Рисуем таблицу рекордов
    void draw_board(sf::RenderWindow& window, int width = 1500);
    //Загружена ли таблица
    bool is_load();
    //Удаляем загруженную таблицу
    void clear();
    //загружаем таблицу
    void load();
};