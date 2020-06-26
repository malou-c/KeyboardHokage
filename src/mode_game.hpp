#pragma once

#include "click.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class ModeGame : Click {
private:
    Texture tex_easy;
    Texture tex_hard;
    Color color_enable = Color(161, 161, 161);
    Color color_def = Color::White;

public:
    Sprite sprite_easy;
    Sprite sprite_hard;
    bool is_hardmode = true;
    //конструктор
    ModeGame(int x, int y);
    //функции
    void update(RenderWindow& window, Event event);
    void draw(RenderWindow& window);
};
