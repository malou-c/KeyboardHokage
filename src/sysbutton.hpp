#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class SysButtonForKB {
private:
    std::string path;
    sf::Image img;
    sf::Texture texture;

public:
    sf::Sprite sprite;
    int code = -1;
    // конструкторы
    SysButtonForKB(sf::String path);
    SysButtonForKB(sf::String path, int code);
    //функции
    void DrawButton(sf::RenderWindow& window);
};
