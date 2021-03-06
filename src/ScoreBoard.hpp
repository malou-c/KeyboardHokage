#pragma once

#include <SFML/Graphics.hpp>

#include "ScoreBoardFile.hpp"
#include <iostream>

//класс для загрузки таблицы рекордов и ее хранения
class ScoreBoard : public ScoreBoardFile {
private:
    sf::Color color_text = sf::Color(0, 0, 0);
    sf::Font font;
    int font_size = 20;
    size_t count_draw = 18;
    //текстура фона
    sf::Texture bckgrnd_pic;

public:
    bool is_loaded = false; //загружена ли таблица рекордов
    bool is_writed = false;
    //фон для таблицы рекордов
    sf::Sprite bckgrnd_sprite;
    //
    sf::Text text;
    std::string out_text = "";
    //для хранения таблицы рекордов
    std::vector<PersonStats> stats;
    //конструктор
    ScoreBoard(int x, int y);
    //Рисуем таблицу рекордов
    void draw_board(sf::RenderWindow& window);
    //загружаем таблицу рекордов из файла
    void load_board();
    //Удаляем загруженную таблицу
    void clear();
};