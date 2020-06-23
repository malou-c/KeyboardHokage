#pragma once

#include <SFML/Graphics.hpp>

#include "file.hpp"
#include <iostream>

//класс для загрузки таблицы рекордов и ее хранения
class ScoreBoard : public File {
public:
    bool is_loaded = false; //загружена ли таблица рекордов
    //фон для таблицы рекордов
    sf::Texture bckgrnd_pic;
    sf::Sprite bckgrnd_sprite;
    //
    sf::Text text;
    std::string out_text = "";
    sf::Font font;
    //для хранения таблицы рекордов
    std::vector<PersonStats> stats;
    //конструктор
    ScoreBoard();
    //Рисуем таблицу рекордов
    void draw_board(sf::RenderWindow& window);
    //загружаем таблицу рекордов из файла
    void load_board();
    //Удаляем загруженную таблицу
    void clear();
};