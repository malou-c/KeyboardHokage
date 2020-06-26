#pragma once
#include "click.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;

class MenuButton : Click {
private:
    int id;
    sf::Font font;         //шрифт текста кнопки
    sf::Image image;       //фото для фона кнопки
    sf::Texture texture;   //текстура для фона кнопки
    sf::Sprite background; //фон для кнопки
    IntRect rect_def;
    IntRect rect_enable;

public:
    bool enable = false;
    //конструкторы
    MenuButton(int x, int y, int id);
    MenuButton(int x, int y, std::string img_path, int id);

    //Узнать id кнопки
    int get_id();

    //Установить границы кнопки
    void set_borders();

    //Проверяет была ли нажата кнопка
    void is_clicked(RenderWindow& window, Event event);

    //рисует кнопку
    void draw(sf::RenderWindow& window);
};