#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class SysButtonForKB {
public:
    sf::Image img;
    sf::Texture texture;
    sf::Sprite sprite;
    std::string path;
    int code = -1;

    // конструкторы
    SysButtonForKB(sf::String path);
    SysButtonForKB(sf::String path, int code);
    //функции
    void DrawButton(sf::RenderWindow& window);
};
