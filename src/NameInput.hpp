#pragma once

#include "click.hpp"
#include <SFML/Graphics.hpp>

extern int ID;

class NameInput : Click {
private:
    //можно ли вводить текст
    bool input_on = false;
    //прямоугольники для спрайтов
    sf::IntRect rect_def;
    sf::IntRect rect_enable;
    //имя
    std::string temp_name = "name";
    sf::Font font;
    int font_size = 25;
    sf::Color font_color = sf::Color::Black;
    sf::Text text;

public:
    sf::Texture texture_nameplace;
    sf::Sprite sprite_nameplace;

    sf::Texture texture_changer;
    sf::Sprite sprite_changer;

    NameInput(int x, int y);

    //отвечает за логику окна для ввода имени пользователя (!НЕ РИСУЕТ)
    void update(sf::RenderWindow& window, sf::Event event);

    //рисует окно для ввода имени
    //(необходимо использовать в связке с window_for_name_input() )
    void draw(sf::RenderWindow& window);

    //возвращает то, что ввел пользователь
    std::string get_input();
};