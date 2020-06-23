#pragma once

#include <SFML/Graphics.hpp>

extern int width;

class NameInput {
private:
    sf::RectangleShape background;
    std::string temp_name = ""; //нужно для хранения пользовательского ввода
    sf::Font font;
    sf::Text text;

public:
    NameInput();

    //отвечает за логику окна для ввода имени пользователя (!НЕ РИСУЕТ)
    void window_for_name_input(sf::RenderWindow& window, sf::Event event);

    //рисует окно для ввода имени
    //(необходимо использовать в связке с window_for_name_input() )
    void draw(sf::RenderWindow& window);

    //возвращает то, что ввел пользователь
    std::string get_input();
};