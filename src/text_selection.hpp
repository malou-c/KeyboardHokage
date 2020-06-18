#pragma once
#include "Folder.hpp"
#include "click.hpp"
#include "section.hpp"
#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>
#include <vector>

using namespace sf;

class TextSelection : Click {
private:
    Vector2i pos;

public:
    //шрифт
    Font font;
    // background
    Texture texture_bg;
    Sprite background;
    //вектор из секций
    std::vector<Section> sections;
    //отступы для секций
    Vector2i indent_sect;
    int count_section; // кол-во секций
    //вектор из названий текстов
    std::vector<std::string> name_folders;

    //конструктор
    TextSelection(int x, int y);
    //функции

    // draw
    void draw(RenderWindow& window);
};