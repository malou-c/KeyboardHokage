#pragma once

#include <SFML/Graphics.hpp>

#include "file.hpp"
#include <iostream>

std::vector<PersonStats> load_board()
{ //Загружаем таблицу

    std::vector<PersonStats> stats;
    File file;
    stats = file.load(); //Загружаем данные (имя время)
    return stats;
}

void draw_board(
        sf::RenderWindow& window,
        std::vector<PersonStats> stats,
        int width = 1500)
{ //Рисует таблицу рекордов
    /*     std::vector<PersonStats> stats;
        File file;
        stats = file.load();//Загружаем данные (имя время) */

    sf::Image image;
    image.loadFromFile("ye.jpg"); //Фон на котором будут отображаться данные

    sf::Texture bckgrnd_pic; //фон для таблицы рекордов
    bckgrnd_pic.loadFromImage(image);

    sf::Sprite bckgrnd_sprite;
    bckgrnd_sprite.setTexture(bckgrnd_pic);
    bckgrnd_sprite.setScale(0.5, 1); //растягивает/сжимает изображение
    bckgrnd_sprite.setPosition(width / 2, 0);

    sf::Text text;
    std::string out_text = "";

    for (unsigned int i = 0; i < stats.size() && i < 50;
         i++) //записываем информацию о превых 50
    {         //пользователях в строку
        out_text
                += (std::to_string((i + 1)) + ')'
                    + (std::string)stats[i].user_name + ' '
                    + (std::to_string(stats[i].time)) + "\n");
    }

    sf::Font font;
    if (font.loadFromFile("fonts/stdFont.ttf")) {
        std::cout << "AAAAAAAA HELP" << std::endl;
        std::cout << "AAAAAAAA HELP" << std::endl;
    } //шрифт
    text.setFont(font);
    text.setString(out_text);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::Red);
    text.setPosition((width / 2) + (width / 6), 10);

    window.draw(bckgrnd_sprite);
    window.draw(text);
}
