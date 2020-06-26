#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ButtonForKB {
private:
    sf::Image img;
    sf::Texture texture;
    std::string path = "images/MK_buttons.png";

public:
    sf::Sprite sprite;
    int code[4];

    // конструкторы
    ButtonForKB();
    //функции
    void DrawButton(sf::RenderWindow& window);
    // get
};
