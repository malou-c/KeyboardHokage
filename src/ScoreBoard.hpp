#pragma once

#include <SFML/Graphics.hpp>

#include "file.hpp"
#include <iostream>

//загружаем таблицу рекордов
std::vector<PersonStats> load_board();

//Рисуем таблицу рекордов
void draw_board(
        sf::RenderWindow& window,
        std::vector<PersonStats> stats,
        int width = 1500);
