#pragma once

#include "click.hpp"
#include <SFML/Graphics.hpp>

class ModeGame : Click {
private:
    sf::Texture tex_easy;
    sf::Texture tex_hard;
    sf::Color color_enable = sf::Color(161, 161, 161);
    sf::Color color_def = sf::Color::White;

public:
    sf::Sprite sprite_easy;
    sf::Sprite sprite_hard;
    bool is_hardmode = true;
    //конструктор
    ModeGame(int x, int y);
    //функции
    void update(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderWindow& window);
};
