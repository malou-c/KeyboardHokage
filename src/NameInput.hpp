#pragma once

#include "click.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

extern int ID;

class NameInput : Click {
private:
    //можно ли вводить текст
    bool input_on = false;
    //прямоугольники для спрайтов
    IntRect rect_def;
    IntRect rect_enable;
    //имя
    std::string temp_name = "name";
    Font font;
    int font_size = 25;
    Color font_color = Color::Black;
    Text text;

public:
    Texture texture_nameplace;
    Sprite sprite_nameplace;

    Texture texture_changer;
    Sprite sprite_changer;

    NameInput(int x, int y);

    //отвечает за логику окна для ввода имени пользователя (!НЕ РИСУЕТ)
    void update(sf::RenderWindow& window, sf::Event event);

    //рисует окно для ввода имени
    //(необходимо использовать в связке с window_for_name_input() )
    void draw(sf::RenderWindow& window);

    //возвращает то, что ввел пользователь
    std::string get_input();
};